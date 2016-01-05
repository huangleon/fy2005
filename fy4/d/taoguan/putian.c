
inherit ROOM;

void create()
{
	int i;
	set("short", "������");
	set("long", @LONG
��ɽ������۶Ա��������������֣�һ������õ�С�����õĹ��߲�������
���Թ�����������ղ������������ϵķ���ƽ���˼�������֮�⡣���������
ᣵʹ���Ҳ�����������﹩����ʲ����񣬰������ź����ͬ���¾ɵĻƶС�
LONG
);
	set("exits", ([ /* sizeof() == 1 */
  		"east" : __DIR__"road2",
 
	]));
	set("outdoors", "taoguan");
      	set("objects", ([
                __DIR__"npc/laoni" : 1,
                __DIR__"npc/nangong_yan" : 1,
                __DIR__"obj/putuan" : 4,
       	]) );
	
	set("coor/x",-10);
	set("coor/y",-100);
	set("coor/z",-50);

	setup();
	for(i=0;i<query("stools");i++)
	set("sitdown_person/"+(string)i,0);

	
}

int valid_leave(object who,string dir)
{
        if(who->query_temp("state/sit"))
                return notify_fail("���������أ������뿪����\n");
        return 1;
}


int invalid_leave(object who)
{
        //if they leave by illegal means like burn sheets, let's clear the stool states
        object *stools;
        if(who->query_temp("state/sit"))
        {
                who->delete_temp("state/sit");
                stools = children(__DIR__"obj/putuan");
                for(int i = 0;i< sizeof(stools);i++)
                {
                        if (present(stools[i],this_object()) && stools[i]->query("sitdown_person") == who)
                        {
                                stools[i]->delete("sitdown_person");
                                return 0;
                        }
                }
        }       
        return 0;
}


