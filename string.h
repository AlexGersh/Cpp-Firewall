#ifndef STRING_H
#define STRING_H

#include "generic-string.h"

class String : public GenericString {
    int length;
    char *data;
    static char *allocate_and_copy(const char *data, int size);

  public:
    String();                  // default constructor
    String(const char *str);   // copy constructor
    String(const String &str); // copy constructor
    ~String();                 // destructor

    /**
     * @brief Sets the contents of this to be a copy of "str".
     * @returns A reference to this.
     */
    String &operator=(const char *str);

    /**
     * @brief Returns true if the contents of this == the contents of other.
     */
    bool operator==(const char *other) const;
    bool operator==(const GenericString &other) const;

    /**
     * @brief Splits this to several sub-strings according to delimiters.
     * @param delimiters A set of characters. For example, when delimieters=" ,"
     * this should be split according to spaces and commas.
     * @returns A String object.
     */
    StringArray split(const char *delimiters) const;

    /**
     * @brief Returns an integer representation of the contents of this.
     * If "this" cannot be represented as integer, returns 0.
     */
    int to_integer() const;

    /**
     * @brief Remove any leading or trailing white-spaces from this.
     * @returns A reference to this.
     */
    String &trim();

    /**
     * @brief Returns a reference to this as "String" instead of "GenericString"
     */
    String &as_string(const GenericString &other);

    /**
     * @brief Returns a pointer to the string
     */
    const char *to_string();
};

#endif
