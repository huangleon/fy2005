#include <ansi.h>
inherit ROOM;
inherit F_LEVEL;

void create()
{
    set("short", BMAG HIW"Ӣ����"NOR);
    set("long", @LONG

Ц��Ȼ�������������ϲ����ң���ѻ��ջ����������б��������Ŀ��ɽ�ڶϡ�
����·�������ѹߡ�
ȴ��Խʯ����������磬ǧ�ű���̾����ʿ�ޣ���������

�峵�������껻���ȸ���������֯�Σ��нֻӺ���
���ž�ʫ��һ�ã�ĥ�������ε���
�����ۣ�������ҡ��ϴ�������Ȥ�����뱭��������忴�������������ꡣ

LONG
    );
    set("exits",
      ([
	"down" : __DIR__"mixian",
      ]));

    set("indoors", "baiyun");
    set("coor/x",30);
    set("coor/y",-160);
    set("coor/z",60);
    setup();
    set("no_fly", 1);
    set("max_lv",75);	
}

int init()
{
    object me = this_player();
    object exitroom = find_object(__DIR__"mixian");
    if (!exitroom)
	exitroom = load_object(__DIR__"mixian");
    if (exp_to_level(me->query("combat_exp"))["level"] >= query("max_lv") && userp(me))
    {
	me->add_temp("block_msg/all",1);
	me->move(exitroom);
	me->add_temp("block_msg/all",-1);
	tell_object(me,MAG"¥�Ϸ�ɫ�������ɣ�ֻ�дֱ�����һ�������ǲ���Ϊ�\n"NOR);
    }
}



/*

	       (\~~~/)            
	       ( ����)        

	       (_____)~��      

��������������- FengYun - ������
������������annie 10.2003
������dancing_faery@hotmail.com
*/

