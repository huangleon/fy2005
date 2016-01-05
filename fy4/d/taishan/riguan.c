// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
#include <ansi.h>
#define FATEMARK "����B/̩ɽ_�ճ�"
inherit ROOM;
void create()
{
  	set("short","�չ۷�");
  	set("long",@LONG
�˴��ǹ����ճ�������ѵط����������£�������ȣ�����ϰϰ������Ʈ����
����Ⱥɽ�������۲����Ļ��ÿ���峿��һ�ֺ����Զ�����ɣ���Ϻ�ճ�������
���Ƶͣ����ڽ��£�����һ���ֿ�������֮�ƣ�����Ӣ�۵��ˣ��޲�Ϊ֮����ӿ����
LONG
  );
    	set("exits",([
	    "south" : __DIR__"zhanlu",
    	]));

	set("outdoors", "taishan");
      	set("coor/x",30);
      	set("coor/y",30);
	set("coor/z",120);
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


void sun_rise(int sunrise, int sunrise_stage)
{
	object *ppls;
    	int i, j;
    	object ob;
    	function f = (:add_fate_mark:);
    	remove_call_out("sun_rise");
    	ob=this_object();
    	if(sunrise_stage == 0 && random(10)<5)
    	{
        	message("vision", HIW"����һƬ����ãã������ʪ���ƺ�����š��ˮ������ʲô�����������\n"NOR, ob);
    	} else
    	if(sunrise == 0)
    	{
        	switch(sunrise_stage)
        	{
            		case 0:
                		message("vision", RED"\nһ���ɫ�Ĺ�â�ո�̽���Һ�ɫ�ĵ�ƽ�ߣ���ʱ�����ϼ����������ա�\n"NOR, ob);
                		message("vision", RED"ɽ�͵Ķ�������Ⱦ�ɺ�ɫ�� \n\n"NOR, ob);
         			call_out("sun_rise", 5, 0, 1);
                		break;
            		case 1:
                		message("vision", HIR"\n�ۺ�ɫ��̫�������Ĵӵ�ƽ��������������غ�Ȼ֮������������\n"NOR, ob);
                		message("vision", HIR"ɽ��ĳ���ֹס�˽��������ڹ�ӭ�µ�һ��ĵ�����\n"NOR, ob);
                		call_out("sun_rise", 5, 0, 2);
                		break;
            		case 2:
                		message("vision", HIR"\nһ�ֺ���ӳ����ߵĲ�ϼ�����شӶ�������\n"NOR, this_object(), ob);
                		message("vision", HIY"\n̫������Ծ���˵�ƽ�ߣ�������ﶼ��������һ�㵭���Ľ�ɫ�� \n"NOR, ob);
                		j = NATURE_D->get_season();
                		if (j == 3)
                		{
                    			message("vision", HIY"\nɽ�µķ�Ҷ��Ҳ�����˵����Ľ�ɫ�����ķ�Ҷ��ϼ���������������ʵ���ɫ��\n"NOR, ob);
                    			message("vision", HIY"����ʧ������ʵ������\n"NOR, ob);
		    			ppls=filter_array(all_inventory(ob),(:userp($1) && interactive($1) && !$1->query(FATEMARK):));
                    		    	if(sizeof(ppls))
						map_array(ppls,f);
	                	}
                break;
        	default:
        		return notify_fail("something wrong\n");
        }
    } else
    {
        switch(sunrise_stage)
        {
        	case 0:
                	message("vision", RED"\n�����Ʋ����������ĺ�������Ľ��¡�����Զ�����������ĵط���������һ˿���͸�֣�\n"NOR, ob);
                	message("vision", RED"�����һƬ������ \n"NOR, ob);
                	call_out("sun_rise", 5, 1, 1);
                	break;
            	case 1:
                	message("vision", HIR"\nת�ۼ���߳�����һ������ɫ��ϼ�⣬ϼ�ⲻͣ�ر任����ɫ������ɫ��ǳ�졢�ۺ��ɫ�ʡ�\n"NOR, ob);
                	message("vision", HIR"̫��Ҳ¶���˺�ͮͮ��С�����������ƻ�ȴû�й�����\n"NOR, ob);
               		call_out("sun_rise", 5, 1, 2);
                	break;
            	case 2:
	                message("vision", HIR"\nһ�ֺ���ӳ����ߵĲ�ϼ�����شӶ�������\n"NOR, ob);
                	message("vision", HIR"\n̫���ƺ������غ��Ƶ�һ��һ����������Ŭ������������������ڳ�������ϼ���������Ʋ㣬\n"NOR, ob);
                	message("vision", HIR"��ɫ��÷ǳ��ɰ���һɲ������ɰ��ĺ�ɫԲ��ͻȻ����ҫ�۵Ĺ�����\n"NOR, ob);
                	j = NATURE_D->get_season();
                	if (j == 4)
                	{
                    		message("vision", HIR"\n���İ��Ʊ�Ⱦ������ɫ��ʣ���ʲ�ͣ�������任��������ĳ����������ŵĹ�������С�\n"NOR, ob);
				ppls=filter_array(all_inventory(ob),(:userp($1) && interactive($1) && !$1->query(FATEMARK):));
                    			if(sizeof(ppls))
                    				map_array(ppls,f);
                	}
                	break;
        	default:
        		return notify_fail("something wrong\n");
        }
    }
}

