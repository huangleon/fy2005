#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "ʯ��");
        set("long", @LONG
�����ʯ��֮�϶�Ƕ��һյʯ�ƣ�ȼ�ű��̵Ļ�⣬����������ʯ�Ρ�ʯ��ֻ
��һ����ʯ�أ�����һ���ǳ�ʪ��������ʯ����ʯ����ɣ���������ӵĲ��ݲβ�
���룬�·��̵�����ʯ����Ѿ��þ���ʯ��������ʯ齣�֮�����һ��ʯ�����Ա�
��������ʯ�ʡ�ʯ����û���ˣ�ʯ���ȴ�У�һ��ʯ�һ�����ܹ������ˡ�
LONG
        );
        set("exits", ([ 
		"south": __DIR__"basement2",
	]));
	set("objects", ([
 		__DIR__"obj/table2": 1,              	
 		__DIR__"obj/skeleton": 1,   
    	]) );
        set("no_fly",1);
        set("item_desc", ([
		"ʯ�": "ʯ��������������Ѳ��ܽ����ˡ���ֻ���������˹������������á�\n",
		"bed": "ʯ��������������Ѳ��ܽ����ˡ���ֻ���������˹������������á�\n",
		"��":  "ʯ��������������Ѳ��ܽ����ˡ���ֻ���������˹������������á�\n",
	 ]));
	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}


void reset()
{
	object *inv;
        object table,skeleton,item1;
        int i,rice,cap; 
        ::reset();
        
        table = present("table", this_object());
        inv = all_inventory(table);
        for (i=0;i<sizeof(inv);i++) {
        	if (inv[i]->query("id")=="parchment") rice=1;
        }
        if (!rice) {
        	item1 = new(__DIR__"obj/parchment");
        	item1->move(table);
        	}
        
        skeleton = present("skull", this_object());
        inv = all_inventory(skeleton);
        for (i=0;i<sizeof(inv);i++) {
        	if (inv[i]->query("id")=="crown") cap=1;
        }
        if (!cap) {
        	item1 = new(__DIR__"obj/crown");
        	item1->move(skeleton);
        }
}


