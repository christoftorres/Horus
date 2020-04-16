#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import zipfile

class InMemoryZip(object):
    def __init__(self):
        self.files = {}

    def append(self, filename_in_zip, file_contents):
        if filename_in_zip not in self.files:
            self.files[filename_in_zip] = ""
        self.files[filename_in_zip] += file_contents

    def writetofile(self, filename):
        with zipfile.ZipFile(filename, mode="w", compression=zipfile.ZIP_DEFLATED, allowZip64=False) as zf:
            for filename_in_zip in self.files:
                zf.writestr(filename_in_zip, self.files[filename_in_zip])
