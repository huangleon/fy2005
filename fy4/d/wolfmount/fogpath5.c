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
		"southup":__DIR__"fogpath",
        "northdown":__DIR__"fogpath4",
	]) );
	set("coor/x",30);
	set("coor/y",-55);
	set("coor/z",25);
       set("outdoors", "wolfmount");
        set("objects", ([
                __DIR__"obj/dropflower" : random(3),
       ]) );

	setup();
	replace_program(ROOM);
}
