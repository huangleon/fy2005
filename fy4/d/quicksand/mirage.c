#include <ansi.h>

inherit ROOM;
#define FATEMARK "����B/������¥"

void create()
{
        set("short", "ɳ��");
        set("long", @long
������ȥ��ֻ�л�ɳ���ޱ��޼ʣ������޾��Ļ�ɳ��û��ˮ��û��������Ҳ
û��ϣ�����˴���Զ��ϡ��ʱ����û��ɳ�����в�Ᵽ�ɳ���Ϻ�Ȼʬ���ݺᣬѪ
��δ�ɡ���Ϊ�ɲ�����Ƶ����ɳ����������ɳ�ڷ籩�о��裬Ψ�������뼹��[33m��[32m
���г�·�����Ǻ���Ϲ������һ����Ҳ��һ���ߵó�ȥ��
long
        );
        set("exits", ([ 
		"southwest" :   __DIR__"sandlin",
		"northwest" :   __DIR__"yangguan",
		"west" : 	__DIR__"desert5",
		"east" : 	__DIR__"desert6",
	]));
        set("outdoors", "quicksand");
	set("coor/x",-900);
	set("coor/y",100);
	set("coor/z",0);
	setup();
}



void init_scenery()
{
        remove_call_out("sun_rise");
        call_out("sun_rise",1, random(2), 0);
}

void add_fate_mark(object ob)
{
	int num = 1 + random(10);
	if(!random(3)) {
		ob->set(FATEMARK,num);
		log_file("riddle/FATE_LOG",
			sprintf("%s(%s) �õ�"+FATEMARK+" "+num+"�� %s \n",
				ob->name(1), geteuid(ob), ctime(time()) ));
	}
}


void sun_rise(int sunrise_stage)
{
	object *ppls;
    	int i, j;
    	object ob;
    	function f = (:add_fate_mark:);
    	ob=this_object();
    	   	
	switch(sunrise_stage)
	{
    		case 0: message("vision", YEL"�ղŻ���������ɳ������ƽϢ������û�з磬һ˿�綼û�У�Ҳû��˿��������\n"NOR, ob);
    			call_out("sun_rise",10,1);
    			break;
    		case 1:
        		message("vision", WHT"\nԶԶ��ȥ����ߵ���ϼ�У������ֳ�������Ӱ�ӡ�\n"NOR, ob);
        		call_out("sun_rise", 5, 2);
        		break;
    		case 2:
        		message("vision", WHT"\n�������Ӱ��Խ��Խ����������������������̣��ֵ����ݷ�����ǽ����ϡ�ɱ档\n"NOR, ob);
        		call_out("sun_rise", 5, 3);
        		break;
    		case 3:
        		message("vision", WHT"\n����֮�䣬�Ʋʱ�ã���Щ�����ֹ�����С�һ�з·����λ�֮�С���\n"NOR, this_object(), ob);
        		ppls=filter_array(all_inventory(ob),(:userp($1) && interactive($1) && !$1->query(FATEMARK):));
            		if(sizeof(ppls))
					map_array(ppls,f);
                	break;
		default:
			return notify_fail("something wrong\n");
	}
}
