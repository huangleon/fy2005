#include <ansi.h>

inherit ROOM;
string *names=({
	__DIR__"maze2",
	__DIR__"yuhuage",
	__DIR__"maze3",
	__DIR__"maze4",
} );

void create()
{
	set("short", HIR"����"NOR);
	set("long", @LONG
����ϰϰ��΢΢��Щ��ζ֮�м����˱ǻ��㣬ԶԶ��ȥ���������۵�С��������
�дУ�һ���̡�һ�ź졢һ�Żơ�һ���ϣ��˵��Ƿ����ƽ�����Ӣ�ͷס����Ƶ�����
��֮�ˣ�����ůʪ����ľ���̣����ݷ�ï�������Ͽɰ�����Ů���ǽ������ɰ�������
��������������˱Ȼ��㡣�������У����Խ��ֲ������ϵ��£�����������
LONG
	);
        set("outdoors", "baiyun");

	set("coor/x",0);
	set("coor/y",-1080);
	set("coor/z",20);

	setup();
}

void reset()
{
	int i,j;
	string temp;
	::reset();
	for (i=0;i<=3;i++)
	{
		j=random(4);
		temp=names[j];
		names[j]=names[i];
		names[i]=names[j];
		names[i]=temp;
	}
	set("exits", ([
		"north" : names[0],
		"south" : names[1],
		"east" : names[2],
		"west" : names[3],
	]));
}

