from binman.etype.blob_named_by_arg import Entry_blob_named_by_arg

class Entry_atf_rmm(Entry_blob_named_by_arg):
    """ARM Trusted Firmware (ATF) RMM blob

    Properties / Entry arguments:
        - atf-rmm-path: Filename of file to read into entry. This is typically
            called rmm.bin or rmm.elf
    """
    def __init__(self, section, etype, node):
        super().__init__(section, etype, node, 'atf-rmm')
        self.external = True
