inherit DOOR_ROOM;
#include <ansi.h>
#include <room.h>

void create()

{
        set("short", "�ּ�յ�");
        set("long", @LONG
��ǰ����Ȼ���ޱ��޼ʵ����ӣ�����Ũ�ܣ�ż�����Լ�����ľ�����µ�����
����һ���ֻ���������Ŀյء���ǰ������ô��յأ���ֵ��ǣ��յ����뾹Ȼ��
����С���ӡ������ϰ���Щֽ��ֽ������һ��ֽ�����ð�ֽ���ɵĵ���������ȴ
Ϳ���˺�ɫ��û��������ֻ����ɱ֮�⡣�յ�����һ��С�ݡ�
LONG
        );
        set("exits", ([ 
		"north" : __DIR__"woods2",
		"south" : __DIR__"woodcabin",
	]));
        set("item_desc", ([
        	"table": "һ�������ϰ���Щֽ��ֽ������һ��ֽ�����ð�ֽ���ɵĵ���������ȴͿ
���˺�ɫ��\n",
        	"����" : "һ�������ϰ���Щֽ��ֽ������һ��ֽ�����ð�ֽ���ɵĵ���������ȴͿ
���˺�ɫ��\n",
        
	]) );
	set("outdoors", "zangbei");
        set("coor/x",-1620);
        set("coor/y",670);
        set("coor/z",0);
	set("map","zbwest");
	setup();
	create_door("south","door","ľ��","north",DOOR_CLOSED);
}
