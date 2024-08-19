#ifndef STRING_H
#define STRING_H

#include "generic-string.h"

class String : public GenericString {
    int length;
    char *data;
    static char *allocate_and_copy(const char *data, int size);

  public:
    String();
    String(const char *str);       // copy constructor
    String(const String &str_obj); // copy constructor
    ~String();                     // destructor

    /**
     * @brief Splits this to several sub-strings according to delimiters.
     * @param delimiters A set of characters. For example, when delimieters=" ,"
     * this should be split according to spaces and commas.
     * @returns pointer to array of strings
     */
    StringArray split(const char *delimiters) const;

    /**
     * @brief Sets the contents of this to be a copy of "str".
     * @returns A reference to this.
     */
    String &operator=(const char *str);

    /**
     * @brief Remove any leading or trailing white-spaces from this.
     * @returns A reference to this.
     */
    String &trim() override;

    /**
     * @brief Returns true if the contents of this == the contents of other.
     */
    bool operator==(const char *other) const;
    bool operator==(const GenericString &other) const;

    /**
     * @brief Returns an integer representation of the contents of this.
     * If "this" cannot be represented as integer, returns 0.
     */
    int to_integer() const;

    /**
     * @brief Returns a reference to this as "String" instead of "GenericString"
     */
    const String &as_string() const;
    String &as_string();

    /**
     * @brief Returns the length of the string
     */
    int get_length() const;

    /**
     * @brief Returns pointer to the data of the String.
     * @note const to avoid overwriting
     */
    const char *get_data() const;
};

GenericString *make_string(const char *str);

#endif
