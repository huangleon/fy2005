// query_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("�����Ӧ���԰�", ({ "board" }) );
	set("location", AREA_WIZ"entrance");
	set("board_id", "query_b");
	set("long",	"����һ���������Լ��µ����԰塣\n" );
	setup();
	set("capacity", 30);
	replace_program(BULLETIN_BOARD);
}
