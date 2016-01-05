#include <ansi.h>

inherit ROOM;
void create()
{
    set("short", "Ǳ��Ȫ");
    set("long", @LONG
�������У�������ب����һ��Ϫ���������ð��������ǧ����ǰ���Ʊ�Ϊ��ɽ��
ǧ�ض��£���ɽ���٣������ȷḻ�����м�����������˲��ܲ��������ʣ�������
�Ƶ��ĵ���Ͱ��Ƴǵĵ��ӵ�Ҳ������������״�������̵�Ȫˮ����ԡ��ʱ��һ��
���ӷ���������������ʵ���÷Ƿ���
LONG
    );
    set("exits", 
      ([ 
		"eastup" : __DIR__"jianlin",
      ]));
    set("outdoors", "baiyun");
    set("coor/x",10);
    set("coor/y",-60);
    set("coor/z",0);

    set("resource/water",1);
    set("liquid/name","Ǳ��Ȫˮ");
    set("liquid/container","Ǳ��Ȫ");
    set("liquid/type", "water");

    setup();
}



void init()
{
    add_action("do_jump", ({"wash","jump"}));

}

int do_jump()
{
    object me;
    int wait;
    me = this_player();
    		
    if (me->query_temp("jiqi/in_pool"))
    		return notify_fail("���Ѿ���ϴ���ˡ�\n");
    if (me->query("gender")=="Ů��")
    	message_vision(YEL"$N����������У�����һưȪˮ����Ө��ˮ��εδӷ��ҡ����Ϲ��䡣����\n"NOR,me);
    else
    	message_vision(YEL"$N��ͨһ������Ȫ�У���ˮ�����������˵�����$N��������Ħ��������\n"NOR,me);
    	
    me->set_temp("jiqi/in_pool",1);
	me->add_temp("jiqi/pool_num",1);
	
	call_out("done_pool",20, me);
	return 1;
}


void done_pool(object me)
{
    int gin,kee,sen;
    string msg;
    
    if(!me)	return;
    	
    if ( me->is_ghost() || environment(me)!= this_object()) 
    {
    		me->delete_temp("jiqi");
    		return;
    }
    	
    if (me->query_temp("jiqi/pool_num")>=3) {
		if (me->query("gender")=="Ů��")
			msg = WHT"�������ش�Ǳ��Ȫ��վ����������ɫ΢�죬����ʪ���Ե�Խ�����������ף����Ŀɰ���\n"NOR;
		else
			msg = WHT"��ӷ�ҶȪ��һԾ���𣬻����������ڣ�͸���ò���ľ�����\n"NOR;
		tell_object(me, msg);
		me->delete_temp("jiqi");
		me->full_me();
	} 
	else {
		tell_object(me,"��е�ȫ���ޱȵ���̩���̲�ס�����ϴһ�Ρ�������\n");
		me->delete_temp("jiqi/in_pool");
	}
	
    return;
}


int valid_leave(object me, string dir){
	
	me->delete_temp("jiqi");
	return ::valid_leave( me, dir);

}


/*
 
               (\~~~/)            
               ( ����)        

               (_____)~��      
   
��������������- FengYun - ������
������������annie 10.2003
������dancing_faery@hotmail.com
*/
