// TIE@FY3
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "�͹���");
        set("long", @LONG
����������ŵ��͹�������ν��սս�������������У�����ǿ�������ƣ���
ͷ���������ꡱ˵�ñ��������ţͷ������������£�����һ�������߽��͹���
��ը�Ĺǽ����ã�������̱���ԭ��һ��һ�Σ����������ĳϻ̳Ͽ�֮ɫ���㰵̾
��������֮�ϡ�����һ�㲻���������������⣬��֪���ֻ���ʲô��
LONG
        );
        set("exits", ([
		"up" : __DIR__"chouchang",
		"down" : __DIR__"heian",
        ]) );
	set("coor/x",0);
	set("coor/y",-40);
	set("coor/z",-130);
	set("no_fight",1);

	setup();
        replace_program(ROOM);
}
 
