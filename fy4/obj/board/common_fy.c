// common_b.c

inherit BULLETIN_BOARD;

void create()
{
    set_name("��������", ({ "board" }) );
	set("location", AREA_FY"fyge");
	set("board_id", "common_fy");
	set("long",	"���Ƿ��Ƹ���ǰ�����磬�������źܶ�ֽ����\n" );
	setup();
	set("capacity", 99);
	replace_program(BULLETIN_BOARD);
}
