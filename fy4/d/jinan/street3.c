#include <room.h>
inherit ROOM;
#include "/questnpc/lovestory1/event_place.h"

void create()
{
  set("short","����̨");
  set("long",@LONG
������Ǽ��ϳ�ÿ������ʥ�˵ļ�̨��̨��������[33mʯ��[32m��һ���������̨��
��һ����š�ʥ����Ȥ������˵������ӵ����������������������̨�£������
����¡��������֮��������һһ�����ɼѻ��������ɣ�������˶����
�ݣ�����̨�������£��߸��������������࣬����Щ���ֵĺ�լ��
LONG
  );
  	set("exits",([
         "northdown":__DIR__"street2",
         "southdown":__DIR__"street4",
//         "eastdown" : __DIR__"pighome",
//         "westdown":__DIR__"qiyuan1",
               ]));
        set("objects", ([
        	BOOKS"chant_30" : 1,
                        ]) );
    	set("outdoors", "jinan");
	set("coor/x",0);
	set("coor/y",60);
	set("coor/z",20);
	setup();


}


int valid_enter(object me)
{

	if(me->query("lovestory1"))
		add_trigger_count(me);
	return 1;
}
