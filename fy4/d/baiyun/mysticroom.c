//Sinny@fengyun 2003
//All Rights Reserved
inherit ROOM;
void create()
{
        set("short", "ʯ��");
        set("long", @LONG
�ڰ��Ƶ���������ɾ����˼����ã�����ȴ��ª����С���ıھ��Ǻ��Ĵ���ʯ��
ֻ�н�������С�źͶ���ʯǽ��һ��խխ��������էһ������Ȼ����Ϊ���������˵�
ʯ�Σ�����ֵ��ǣ�ʯ����յ����ģ�����һ��˶�������ͭ����һ����Ӣ������
���۵��������⣬�����һ��������ھ���ǰ�������Ų���ʱ��ʱͣ�ھ���ǰ����
�ָ����Ķ�������Ц����ŭ����ϲ���򱯡�����
LONG
           );
        set("exits",
            ([
	    ]));
	set("objects",
 	   ([
        __DIR__"npc/southprince" : 1,
	    ]));
	    set("item_desc",	([
	    	"����":		"������Ȼ�����ع��ţ�Ҳ���п���ײ������ȥ��(leave)\n",
	    	"window":	"������Ȼ�����ع��ţ�Ҳ���п���ײ������ȥ��(leave)\n",
	    ]));
	    
        set("indoors", "baiyun");
		set("no_fly",1);
		set("coor/x",0);
		set("coor/y",-1030);
		set("coor/z",0);
		setup();
}

void init()
{
	add_action("do_leave", "leave");
}

int do_leave()
{
	object me = this_player();
	
	if (me->is_busy() || me->is_fighting())
		return notify_fail("��������æ��\n");

	tell_object(me,"���þ�ȫ����ײ����ʵ��һ������������Ծ����ȥ�� \n");
	
	tell_object(me,"ʯ�����Ȼ����ӿ�Ĵ󺣡� \n");
	tell_object(me,"������һ������ʲôҲ��֪���ˡ����� \n");
	me->unconcious();
	me->move(load_object(__DIR__"nujiao"));
//	me->revive();
	return 1;
}


/*
 
               (\~~~/)            
               ( ����)        

               (_____)~��      
   
��������������- FengYun - ������
������������annie 10.2003
������dancing_faery@hotmail.com
*/
