// Room: fanyinshi.c --- by MapMaker

inherit ROOM;

void create()
{
	set("short", "������");

	set("long", @LONG
���������ɽ���ϵ����������Ũ���У���ϡ���Էֱ��"������"��������
���Ѱ���Ĵ��֡�����ϵĳ�����һֱ���š��������ĵƹ�ȴ�����ղ�����ǽ�⣬
ԶԶ����ȥ��ֻ��һƬ����뵣�Ҳ��֪�����̣����ƣ������������ǹ��ŵģ�
��ȴ�صò�����һ���Ƶ���ɫ�������������翵Ĵ��ŷ���Ʈ������
LONG);
	set("exits",([
	"out":__DIR__"nilu6",
	"north":__DIR__"bigyard",
	]) );
	//}}
        set("outdoors", "shanliu");
	set("objects", ([
	__DIR__"npc/tiansisi" :1,
	]) );
	set("coor/x",-2);
	set("coor/y",50);
	set("coor/z",60);
	setup();
	replace_program(ROOM);
}
