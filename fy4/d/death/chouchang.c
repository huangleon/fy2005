// TIE@FY3
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "�鳦��");
        set("long", @LONG
�����ƺ�������ǲ�ͬ��û�д��̾ߣ����еĶ������Ǽ��ѹ��Ӻͼ��ѽ�ţ
���������������õ��ʿ����ӣ�����һ��������һ���ҽУ�������������ͷƤ����
���㷢���Ժ�����������ˣ���صĳ�������ֻ��Ż�����������ֶ���һ������֮
�ġ��������±�����һ���ˡ�
LONG
        );
        set("exits", ([
		"up" : __DIR__"tuoke",
		"down" : __DIR__"youguo",
        ]) );
	set("coor/x",0);
	set("coor/y",-40);
	set("coor/z",-120);
	set("no_fight",1);

	setup();
        replace_program(ROOM);
}
 
