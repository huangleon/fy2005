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
	"west" : __DIR__"teashop",
	"north": __DIR__"nstreet3",
	"south": __DIR__"nstreet1",
	]));
        set("objects", ([
	]) );
	set("outdoors", "biancheng");
        set("coor/x",-10);
        set("coor/y",20);
        set("coor/z",0);
	set("map","zbwest");
	setup();
	replace_program(ROOM);
}
