// TIE@FY3
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
�Թ��������֮ͽ����Т֮�˶మ��Ū�Ƿǣ�������ģ���������������ߴ�
���鹴ȥ��ͷ��ʹ֮�ڲ����ԣ���Ḵ���������ٰΣ�����ѭ����ֱ�������ĵ���
ɥ������Ϊ�ˣ��㲻���ٷ���ҵ�������±��ǰ�Ƥ����
LONG
        );
        set("exits", ([
		"up" : __DIR__"yandu",
		"down" : __DIR__"bopi",
        ]) );
	set("coor/x",0);
	set("coor/y",-40);
	set("coor/z",-50);
	set("no_fight",1);

	setup();
        replace_program(ROOM);
}
 
