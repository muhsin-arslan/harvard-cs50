#include <cs50.h>
#include <stdio.h>

string check_card(long card_number);
int get_card_number_length(long card_number);
bool check_card_number_length(int card_number_length);
bool validate_card_number(long card_number);
string get_card_brand(long card_number);

int main(void)
{
    long card_number = get_long("Card Number: ");
    string card_status = check_card(card_number);
    printf("%s\n", card_status);
}

string check_card(long card_number)
{
    int card_number_length = get_card_number_length(card_number);
    bool is_card_number_length_valid = check_card_number_length(card_number_length);

    // First check for valid length of card number.
    if (!is_card_number_length_valid)
    {
        return "INVALID";
    }
    else
    {
        // If card has valid length, check if card number valid
        bool is_card_number_valid = validate_card_number(card_number);

        // If card number is not valid
        if (!is_card_number_valid)
        {
            return "INVALID";
        }
        else
        {
            // If card number valid try to find brand of card.
            return get_card_brand(card_number);
        }
    }
}

int get_card_number_length(long card_number)
{
    int length = 0;
    long divided_number = card_number;

    while (divided_number > 0)
    {
        divided_number = divided_number / 10;
        length++;
    }

    return length;
}

bool check_card_number_length(int card_number_length)
{
    return (card_number_length == 13 || card_number_length == 15 || card_number_length == 16) ? true : false;
}

bool validate_card_number(long card_number)
{
    // Find digits that were multiplied by 2
    int multiplied_digit_1, multiplied_digit_2, multiplied_digit_3, multiplied_digit_4, multiplied_digit_5, multiplied_digit_6,
        multiplied_digit_7, multiplied_digit_8;

    multiplied_digit_1 = ((card_number % 100) / 10) * 2;
    multiplied_digit_2 = ((card_number % 10000) / 1000 * 2);
    multiplied_digit_3 = ((card_number % 1000000) / 100000 * 2);
    multiplied_digit_4 = ((card_number % 100000000) / 10000000 * 2);
    multiplied_digit_5 = ((card_number % 10000000000) / 1000000000 * 2);
    multiplied_digit_6 = ((card_number % 1000000000000) / 100000000000 * 2);
    multiplied_digit_7 = ((card_number % 100000000000000) / 10000000000000 * 2);
    multiplied_digit_8 = ((card_number % 10000000000000000) / 1000000000000000 * 2);

    multiplied_digit_1 = (multiplied_digit_1 % 100 / 10) + (multiplied_digit_1 % 10);
    multiplied_digit_2 = (multiplied_digit_2 % 100 / 10) + (multiplied_digit_2 % 10);
    multiplied_digit_3 = (multiplied_digit_3 % 100 / 10) + (multiplied_digit_3 % 10);
    multiplied_digit_4 = (multiplied_digit_4 % 100 / 10) + (multiplied_digit_4 % 10);
    multiplied_digit_5 = (multiplied_digit_5 % 100 / 10) + (multiplied_digit_5 % 10);
    multiplied_digit_6 = (multiplied_digit_6 % 100 / 10) + (multiplied_digit_6 % 10);
    multiplied_digit_7 = (multiplied_digit_7 % 100 / 10) + (multiplied_digit_7 % 10);
    multiplied_digit_8 = (multiplied_digit_8 % 100 / 10) + (multiplied_digit_8 % 10);

    int sum1 = multiplied_digit_1 + multiplied_digit_2 + multiplied_digit_3 + multiplied_digit_4 + multiplied_digit_5 +
               multiplied_digit_6 + multiplied_digit_7 + multiplied_digit_8;

    // Find digits that were not multiplied by 2
    int unmultiplied_digit_1, unmultiplied_digit_2, unmultiplied_digit_3, unmultiplied_digit_4, unmultiplied_digit_5,
        unmultiplied_digit_6, unmultiplied_digit_7, unmultiplied_digit_8;

    unmultiplied_digit_1 = (card_number % 10);
    unmultiplied_digit_2 = ((card_number % 1000) / 100);
    unmultiplied_digit_3 = ((card_number % 100000) / 10000);
    unmultiplied_digit_4 = ((card_number % 10000000) / 1000000);
    unmultiplied_digit_5 = ((card_number % 1000000000) / 100000000);
    unmultiplied_digit_6 = ((card_number % 100000000000) / 10000000000);
    unmultiplied_digit_7 = ((card_number % 10000000000000) / 1000000000000);
    unmultiplied_digit_8 = ((card_number % 1000000000000000) / 100000000000000);

    int sum2 = unmultiplied_digit_1 + unmultiplied_digit_2 + unmultiplied_digit_3 + unmultiplied_digit_4 + unmultiplied_digit_5 +
               unmultiplied_digit_6 + unmultiplied_digit_7 + unmultiplied_digit_8;

    int sum3 = sum1 + sum2;

    return (sum3 % 10 == 0) ? true : false;
}

string get_card_brand(long card_number)
{
    int card_number_length = get_card_number_length(card_number);
    long digits_for_amex = card_number;
    long digits_for_master = card_number;
    long digit_for_visa = card_number;

    while (digits_for_amex >= 10000000000000)
    {
        digits_for_amex /= 10000000000000;
    }

    if ((digits_for_amex == 34 || digits_for_amex == 37) && card_number_length == 15)
    {
        return "AMEX";
    }

    while (digits_for_master >= 100000000000000)
    {
        digits_for_master /= 100000000000000;
    }

    if ((digits_for_master >= 51 && digits_for_master <= 55) && card_number_length == 16)
    {
        return "MASTERCARD";
    }

    while (digit_for_visa >= 10)
    {
        digit_for_visa /= 10;
    }

    if ((digit_for_visa == 4) && (card_number_length == 13 || card_number_length == 16))
    {
        return "VISA";
    }

    return "INVALID";
}