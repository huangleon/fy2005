#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "ƽ����");
        set("long", @LONG
��������������ȥ���ܷ��У��ж�������ǰ����¼��ת�ز��У�������
���˵ģ�Ѻ��ʮ�˲�����ܿ࣬���ǿ�ת��Ͷ̥�Ĺ�꣬��;���������߹�ƽ��
�������κ���ȥͶ̥����Ϊ�˵���Ͷ�����˱ؾ�֮·������ʮ�ְ��������������
��������ٴ���ʮ�ꡣƽ������������[33m�����ǡ�����ͤ[32m��ȥ����
LONG
        );
        set("exits", ([
		"southwest": __DIR__"nanbank",
		"southeast": __DIR__"hospital",
		"northeast": __DIR__"mengpo",
		"northwest": __DIR__"wangsi",
		"south" : __DIR__"aihe",
        ]) );
	set("coor/x",0);
	set("coor/y",-40);
	set("coor/z",-190);
	set("no_fight",1);
	set("no_meal","���Ȼ���ֿ��е�ʳ����ˮ���˿�ɬ�����࣬�Ͽ����۵����˳�����\n");
	setup();
        
}
 
