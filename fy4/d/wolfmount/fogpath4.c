inherit ROOM;

void create()
{
	set("short", "����ʯ��");

	set("long", @LONG
ɽ���������ƣ�С·���Ѷ��ϣ�һ�ԴԲ�֪����С����ɽ����ҡҷ����ֵ����
ʱ�ڣ�бб��ʯ�����仨�ͷס�̤���仨����ɳɳ��֮���ڼž���ɽ�����ƺ�����
����������Ҳ�����˸���ľҶ�Ͱٻ��ķҷ���������Զɽ��䡣
LONG);

	set("type","road");
	set("exits",([
        "southup":__DIR__"fogpath5",
        "northdown":__DIR__"fogpath3",
	]) );
       set("outdoors", "wolfmount");
        set("objects", ([
                __DIR__"obj/dropflower" : 3,
       ]) );
	set("coor/x",30);
	set("coor/y",-50);
	set("coor/z",20);

	setup();
	replace_program(ROOM);
}
