inherit ROOM;

void create()
{
	set("short", "ʮ����");

	set("long", @LONG
ɽ·����������У������ɼ���᾵Ĺ�ʯ���ң��������������ٻ��ƣ���ãã
��ɽ���п�ȥ����������ɭ�ɲ�������˱����µĵ��ƣ������ɽ��ʯ�䣬���ﴩ
�С�Ũ���в�ʱð��һ��˫������â�Ĺ��ۺݺݵض����������
LONG);

	set("type","road");
	set("exits",([
		"eastup":__DIR__"18pan1",
        "northwest":__DIR__"18pan2",
	]) );
	set("coor/x",-10);
	set("coor/y",50);
	set("coor/z",-40);
       set("outdoors", "wolfmount");
	set("objects",([
     		__DIR__"npc/wenxin":1,
    	]) ); 
    	setup();
	replace_program(ROOM);
}
