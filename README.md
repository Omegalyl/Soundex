# Soundex

## What is Soundex
Soundex is a phonetic algorithm for indexing names by sound, as pronounced in English. The goal is for homophones to be encoded to the same representation so that they can be matched despite minor differences in spelling. The algorithm mainly encodes consonants; a vowel will not be encoded unless it is the first letter. Soundex is the most widely known of all phonetic algorithms (in part because it is a standard feature of popular database software such as DB2, PostgreSQL, MySQL, SQLite, Ingres, MS SQL Server, Oracle and SAP ASE. Improvements to Soundex are the basis for many modern phonetic algorithms
## Histroy
Soundex was developed by Robert C. Russell and Margaret King Odell and patented in 1918 and 1922. A variation, American Soundex, was used in the 1930s for a retrospective analysis of the US censuses from 1890 through 1920. The Soundex code came to prominence in the 1960s when it was the subject of several articles in the Communications and Journal of the Association for Computing Machinery, and especially when described in Donald Knuth's The Art of Computer Programming.

The National Archives and Records Administration (NARA) maintains the current rule set for the official implementation of Soundex used by the U.S. government. These encoding rules are available from NARA, upon request, in the form of General Information Leaflet 55, "Using the Census Soundex". 
## How Soundex codes are generated
A Soundex code is a four-character string in the form of an initial letter followed by three digits, such as Z452. The initial letter is the first letter of the surname, and the three digits are drawn from the sounds within the surname using the following algorithm:

    1 Discard all non-letter characters from the surname: dashes, spaces, apostrophes, and so on.

    2 Encode each letter as a digit using the table below.
    
 Digit | Represents the letter|
 ------|----------------------|
   0   | A E I O U H W Y
   1   | B F P V  
   2   | C G J K Q S X Z 
   3   | D T 
   4   | L
   5   | M N  
   6   | R
    
    3 Coalesce adjacent duplicate digits from the code (e.g. 222025 becomes 2025).
    
    4 Replace the first digit of the code with the first letter of the original name, converting to uppercase.
    
    5 Remove all zeros from the code.
    
    6 Make the code exactly length 4 by padding with zeros or removing the excess.
 Example "Rohit" (R300) and "O'Conner" (O256).
