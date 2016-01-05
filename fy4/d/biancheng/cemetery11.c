#include <ansi.h>
inherit __DIR__"cemetery";

string *names=({
	__DIR__"cemetery11",
	__DIR__"cemetery8",
	__DIR__"cemetery10",
	
} );


void create()
{
        set("short", "�س�");
        set("long", @LONG
��ɫ��ɭ����Ҳ���䣬Զ���ߵ�������ص���ĺ��澹��һƬ�ޱ��޼ʵĻķء�
��Ȼ�ǰ��죬�ķؼ���Ȼ��������Ҳ��Ȼ���Թ����ˡ����������������Ե�����
�谵������У�һֻ��Ӱ�����������������������������������м������硣����
Ҳ����ɽ����ˮ����Ұ���ķء�
LONG
        );
        set("outdoors", "biancheng");
        set("coor/x",-105);
	set("coor/y",10);
	set("coor/z",0);
	set("no_lu_letter",1);
	setup();
}

void reset()
{
	int i,j;
	string temp;
	::reset();
	for (i=0;i<=2;i++)
	{
		j=random(3);
		temp=names[j];
		names[j]=names[i];
		names[i]=names[j];
		names[i]=temp;
	}
	set("exits", ([
		"west" : __DIR__"cemetery_c",
		"north" : names[0],
		"east" : names[1],
		"south" : names[2],
	]));
}
