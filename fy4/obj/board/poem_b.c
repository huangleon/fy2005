// common_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("�������˼�", ({ "board" }) );
	set("location", AREA_FY"poemp");
	set("board_id", "poem_b");
	set("long",	"����һ���������������˴�ʱ���á�\n" );
	setup();
	set("capacity", 60);
	replace_program(BULLETIN_BOARD);
}
