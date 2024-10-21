#ifndef RLE_H
#define RLE_H

/**
 * Run-length encodes contents of file and writes output to filename.rle
 *
 * @returns
 * When successful returns the output filename, otherwise NULL
 */
char *rlencode(char *filename);

/**
 * Decodes the run-length encoded contents of file with filename.
 * filename must end in `.rle`.
 * Writes output to file with same filename without the `.rle` extension
 *
 * @returns
 * When successful returns the output filename, otherwise NULL
 */
char *rldecode(char *filename);

#endif