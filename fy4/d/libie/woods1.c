// Room: woods1.c --- by MapMaker

inherit ROOM;

void create()
{
	set("short", "С����");

	set("long", @LONG
С������һƬ���ţ����紵��ľ��������û�У����綼�����������������
����ʪ�����쿴����̫��������Ҳ�������ǳ��������Ǹ����������Ҳ��������̫
���ΪֻҪһ��·�����ߵó�ȥ��
LONG);

	//{{ --- by MapMaker
	set("type","forest");
	set("exits",([
	"south":__DIR__"brook",
	"north":__DIR__"woodsedge",
	]) );
        set("outdoors", "libie");
	set("coor/x",20);
	set("coor/y",20);
	set("coor/z",0);
	//}}

	setup();
	replace_program(ROOM);
}
