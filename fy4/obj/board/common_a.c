// common_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("һ����;���԰�", ({ "board" }) );
	set("location", AREA_GUANWAI"inn");
	set("board_id", "common_a");
	set("long",	"����һ���������Լ��µ����԰塣\n" );
	setup();
	set("capacity", 300);
	replace_program(BULLETIN_BOARD);
}
