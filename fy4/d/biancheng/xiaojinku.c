inherit DOOR_ROOM;
#include <ansi.h>
#include <room.h>

void create()

{
        set("short", "�����");
        set("long", @LONG
������խ��һ���ţ����������ߡ�������խ������ռ�ĵط�ȴ���խ����
��û�����ƣ�Ҳû�б�־��ֻ����һյ�ۺ�ɫ�ĵơ�������ʱ�򣬾ͱ�ʾ��ط���
��ʼӪҵ����ʼ׼�����������Ǯ�ˡ���Ϩ�ŵ�ʱ�������Ｘ����δ�������˳�
������ȻҲû���˽�ȥ�����ﾹ������������ĵط���
LONG
        );
        set("exits", ([ 
	"north": __DIR__"road5",
	"south": __DIR__"xiaojinku2",
	]));
        set("objects", ([
	]) );
        set("coor/x",-40);
        set("coor/y",-10);
        set("coor/z",0);
	set("map","zbwest");
	setup();
	create_door("south","door","խ��","north",DOOR_CLOSED);
}
