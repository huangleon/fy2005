// street4.c

#include <room.h>
inherit ROOM;
void create()
{
  set("short","����");
  set("long",@LONG
�������һƷ�ղ�����˱��ؼ��Ϻ������޽������񱮡���������ԣ���
�����ÿ���ʡ����˾ݴ�������������񱮡��˴������ưܲ������������ˡ���
���������˺󣬵�����³�ӵܴ���ķ�����һ�ղ���һ�գ���ϧ��ŭ֮�࣬�����
�ڴ��������񱮣������������˱صù������У�һ�ɲ���������С����ϲ�Զ����
�½������Ÿ�ۡ��
LONG
  );
  set("exits",([
         "northup":__DIR__"street3",
         "south":__DIR__"street5",
//         "west":__DIR__"mjgate",
         "east":__DIR__"firstbrook",
               ]));
	set("objects", ([
		__DIR__"npc/doorguard" : 1,
	]));
    set("outdoors", "jinan");
	set("coor/x",0);
	set("coor/y",40);
	set("coor/z",0);
	setup();

}

int valid_leave(object me, string dir)
{
        object *inv;
        object ob;
        int i;
        if( userp(me)) 
        {
            if( dir == "south"  && ob=present("yinxian", this_object())) 
             {
                	inv = all_inventory(me);
                    for(i=0; i<sizeof(inv); i++) 
               {
                        	if((inv[i]->query("weapon_prop")) && (inv[i]->query("equipped")))
                              return notify_fail(ob->name()+"��ȭ��������������н�����\n");
             		}
        	}
    }
        return 1;
}


