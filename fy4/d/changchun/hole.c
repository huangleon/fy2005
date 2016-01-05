
inherit ROOM;
string *names=({
	__DIR__"hole7",
	__DIR__"hole1",
	__DIR__"hole5",
	__DIR__"hole6",
} );
void create()
{
	set("short", "��Ѩ");
	set("long", @LONG
ɽ�����ض����������䣬����������֮��������һ�㣬���շ��������й�֮��
Խ������Խ����ʪ��������������Ѽ���ָ��
LONG
	);
	set("objects",([
		AREA_TIEFLAG"npc/master" : 1,
	] ) );
	set("coor/x",11);
	set("coor/y",-10);
	set("coor/z",-10);
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
