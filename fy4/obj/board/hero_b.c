// common_b.c

inherit BULLETIN_BOARD;
#include <ansi.h>

void create()
{
    set_name(CYN"��������Ӣ�۰�"NOR, ({ "hero board","board" }) );
        set("location", AREA_GUANWAI"peak");
    set("board_id", "hero_b");
    set("long", "�Ƕ����µ�һ��,Ц������,�ݺ��ĺ�,һ������ɽ��,������ī�Ÿ�֮ʱ!!\n" );
	setup();
    set("capacity", 100);
	replace_program(BULLETIN_BOARD);
}
