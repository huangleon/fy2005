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
        "southup":__DIR__"fogpath3",
		"northwest":__DIR__"pubyard",
	]) );
       set("outdoors", "wolfmount");
        set("objects", ([
                __DIR__"obj/dropflower" : 1,
       ]) );
	set("coor/x",30);
	set("coor/y",-30);
	set("coor/z",0);

	setup();
	replace_program(ROOM);
}
