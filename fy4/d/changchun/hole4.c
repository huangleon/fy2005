
inherit ROOM;
string *names=({
	__DIR__"hole6",
	__DIR__"hole2",
	__DIR__"stone1",
	__DIR__"hole1",
} );
void create()
{
	set("short", "��Ѩ");
	set("long", @LONG
ɽ�����ض����������䣬����������֮��������һ�㣬���շ��������й�֮��
Խ������Խ����ʪ��������������Ѽ���ָ��������Զ���ƺ�͸��һ��ƹ⡣
LONG
	);
	set("coor/x",100);
	set("coor/y",-20);
	set("coor/z",-20);
        set("no_magic",1);
        set("no_spells",1);
	setup();
}

int valid_leave(object me,string dir)
{
	if (userp(me) && query("exits/"+dir)==__DIR__"stone1")
		me->set_temp("marks/pass_hole_to_yedi",1); 
    return 1;
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
 
