inherit ROOM;

void create()
{
	set("short", "ʮ����");

	set("long", @LONG
ɽ·����������У������ɼ���᾵Ĺ�ʯ���ң��������������ٻ��ƣ���ãã
��ɽ���п�ȥ����������ɭ�ɲ�������˱����µĵ��ƣ������ɽ��ʯ�䣬���ﴩ
�С��߳�ʮ����ǰ��������ɽ��һ�ա��������룡
LONG);

	set("type","road");
	set("exits",([
		"southup":__DIR__"wolfhill",
		"enter":__DIR__"tigerdelve",
		"westdown":__DIR__"18pan3",
	]) );
       set("outdoors", "wolfmount");
	set("objects",([
     		__DIR__"npc/wenwen":1,
    	]) ); 
	set("coor/x",0);
	set("coor/y",50);
	set("coor/z",-30);
	setup();
	replace_program(ROOM);
}
