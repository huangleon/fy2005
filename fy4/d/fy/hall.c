#include <ansi.h>
inherit ROOM;
int done_jiqi(object me);

//	void load_item(object me);
int	do_update(object me);
void	reset_player(object ob);

void create()
{
    set("short", HIY"�����콾��"NOR);
    set("long", @LONG
����һ�����϶���ʥ�Ĵ���ʯ�ţ���Լ���ڰ���ǰ�����ϰ߰ߵ�㣬�绯������
��˵������ʴ���ٷ��ν����¶�ŮӢ�۵ĵط������Ǳ��ν���Ӣ�۶���Ϊ����֮
�����ǵ��¼�ǧ����Ϊ���˴��̡�΢��ϰϰ���棬������������ɣ�[37m�������[32m��
���֮�������ؽ��������ѧ�����м�����ߡ��ɴ����ϣ���������Ӣ����������
�����ֵ�һ�˵����ڡ���[1;31m����Ӣ�۰�[0;32m��
LONG
    );
    set("exits", ([ 
	"south" : __DIR__"nwind4",
	"north" : __DIR__"jinshuihe",
	"up" : __DIR__"mirrorgallery",
      ]));
	set("no_fight",1);
	set("no_fly",1);
    set("outdoors", "fengyun");
    set("coor/x",0);
    set("coor/y",240);
    set("coor/z",0);
    set("map","fynorth");
    setup();

}

void init(){
	add_action("do_jiqi","tuna");
}

int do_jiqi(){
        object me;
        mapping buff_list, condition;
  		string *a;
  		int i;
  	      
        me = this_player();
		if (me->is_busy())	
			return notify_fail("��������æ��\n");
	
		"/cmds/std/remove.c"->main(me,"all");
    	
    	condition = me->query_all_condition();
    	buff_list = me->query_temp("buff");
    	if (sizeof(condition))
    		return notify_fail("��������״���޷��������ɡ�\n");


		if (sizeof(buff_list)) {
			a = keys(buff_list);
			for (i=0;i<sizeof(buff_list);i++) {
				if (buff_list[a[i]])
					return notify_fail("��������״���޷��������ɡ�\n");
    		}
    	}	
    	
    	if (me->query_temp("jiqi/in_tuna"))
    		return notify_fail("�����������С�\n");
    			
	message_vision(HIG"\n����ϰϰ��$N˫���鱧�������ڷ����콾�ţ��������ɵ���֮����\n"NOR,me);
	me->set_temp("jiqi/in_tuna",1);
	me->add_temp("jiqi/num",1);
	me->perform_busy(3);
	call_out("done_jiqi",4, me);
//	done_jiqi(me);
	return 1;
}

int done_jiqi(object me) {
	
	string msg;
	
	if (!me || me->is_ghost() || environment(me)!= this_object())
		return 1;
		
	if (me->query_temp("jiqi/num")>=3) {
		msg = HIR"
һ�������ֻ���������������������ȫ������֮�У�����һ����
ˮ���ڵ�����ת�������ޱȡ�ǡ��ˮ����ã��������ᣬ������ʮ��
����һһ���ƣ����Ǵ󹦸���ˡ�\n\n"NOR;
		me->delete_temp("jiqi");
		do_update(me);
		if (me->query("eff_kee")>me->query("max_kee")) me->set("eff_kee",me->query("max_kee"));
		if (me->query("eff_gin")>me->query("max_gin")) me->set("eff_gin",me->query("max_gin"));
		if (me->query("eff_sen")>me->query("max_sen")) me->set("eff_sen",me->query("eff_sen"));
		if (me->query("kee")>me->query("eff_kee")) me->set("kee",me->query("eff_kee"));
		if (me->query("gin")>me->query("eff_gin")) me->set("gin",me->query("eff_gin"));
		if (me->query("sen")>me->query("eff_sen")) me->set("sen",me->query("eff_sen"));
	} else {
		msg = YEL"
һ�������ֻ���������������������ȫ������֮�У�����һ����
ˮ���ڵ�����ת�������ޱȡ�\n\n"NOR;
		me->delete_temp("jiqi/in_tuna");
	}
	tell_object(me,msg);
	me->stop_busy();
	return 1;
}


int	do_update(object me){
	
        if (!objectp(me) 
        	|| me->is_ghost())
        	return 1;
        
// ���¼��㾫����ֵ�������logind�еļ�����ͬ��	

// �޸ĺ��к�ʽͳһ���� :: annie
		"/cmds/std/unwield.c"->main(me,"all");
		"/cmds/std/remove.c"->main(me,"all");
        "/feature/nada.c"->reset_player_status(me);
        me->save();	
        return 1;

}



