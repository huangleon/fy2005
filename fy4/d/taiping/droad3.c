inherit ROOM;
#include <ansi.h>
int blinding(object me);
int bbqthem(object me, object obj);

void create()
{
        set("short", "����С��");
        set("long", @LONG
С�����û�еƹ⣬һ�㶼û�С�һ��˵��������ɭ������������ͬ���
ʯ���·����ʯ����Ұ�ݾ�������ߣ���Ȼ��ط�ƽʱ���������������������ǰ�
��ɫ�ĸ�ǽ��û�д��ӣ�Ҳû��������
LONG
        );
        set("exits", ([ 
		"west": __DIR__"droad2",
		"northeast": __DIR__"droad4",
	]));
        set("outdoors", "taiping");
	set("objects", ([
        	__DIR__"npc/killer" : 1,
        ]) );
	set("item_desc", ([
 		"grass":	"С�����ˣ�Ұ���Ѿ���������ˡ�\n",
		"Ұ��":		"С�����ˣ�Ұ���Ѿ���������ˡ�\n",    
	]));
	set("coor/x",30);
	set("coor/y",-10);
	set("coor/z",0);
	set("map","taiping");
	setup();

}
