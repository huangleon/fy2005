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
        "northdown":__DIR__"fogpath5",
		"southeast":__DIR__"cloudedge",
	]) );
       set("outdoors", "wolfmount");
	set("objects",([
     		__DIR__"npc/fashi":1,
    	]) ); 
	set("coor/x",30);
	set("coor/y",-60);
	set("coor/z",30);
	setup();
	replace_program(ROOM);
}
