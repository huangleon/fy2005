// wizard_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("���������", ({ "board" }) );
	set("location", AREA_WIZ"hall");
	set("board_id", "wizard_b");
	set("long",
		"����һ����������Ա���໥���Եİ塣\n" );
	setup();
	set("capacity", 88);
	replace_program(BULLETIN_BOARD);
}
