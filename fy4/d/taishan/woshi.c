// Room: woshi.c --- by MapMaker

inherit ROOM;

void create()
{
    set("short", "���С��");

	set("long", @LONG
���ֻ��һ����������������ҵĻ�,�Ǿ���"��"�ˡ����г����Ŵ���,����
����.�б�������ʰ���쳣�����ྲ.��˿����͸������,�Եø��ⰲ��.
LONG);

	//{{ --- by MapMaker
	set("type","indoors");
	set("exits",([
	"east":__DIR__"dating",
	]) );
	//}}
        set("indoors", "taishan");
	set("coor/x",-10);
	set("coor/y",70);
	set("coor/z",150);

	setup();
	replace_program(ROOM);
}
