// wizard_j.c

inherit BULLETIN_BOARD;
void create()
{
	set_name("���������", ({ "idea board", "board" }) );
	set("location", AREA_WIZ"jobroom");
	set("board_id", "wizard_j");
	set("long",	"����һ��ר��Ϊ��Һ͹�����Ա��ͨ������塣\n" );
	setup();
        set("capacity", 49);
        replace_program(BULLETIN_BOARD);
}
