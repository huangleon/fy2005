inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "����");
        set("long", @LONG
һ���ϱ����С�ֺ����С��Ķ��࣬�����������ٳߡ�С�ֵ�һ�ˣ����ޱ�
�޼ʵĲ�ԭ��С�ֵ���һ�ˣ�Ҳ���ޱ��޼ʵĲ�ԭ�����ڽ��ϣ��������ǽ䱸����
�⣬��Զ��С��û�йٸ���û�к��ţ������˵�һ�ж�Թ��Ψһ���;�����ǳ�
�ʵĵ������ϵ�Ѫ��        
LONG
        );
        set("exits", ([ 
	"west" : __DIR__"silkshop",
	"north": __DIR__"nstreet2",
	"south": __DIR__"road2",
	"east": __DIR__"nanbank",
	]));
        set("objects", ([
	]) );
	set("outdoors", "biancheng");
        set("coor/x",-10);
        set("coor/y",10);
        set("coor/z",0);
	setup();
	replace_program(ROOM);
}
