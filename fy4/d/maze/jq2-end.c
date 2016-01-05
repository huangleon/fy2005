// Sinny-silencer@fy4 workgroup 


// well, should we let everyone come, or just the quester?

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "�޼���");
	set("long", @LONG
һ��ʮ�ֿ����Ĵ��ã��ĽǸ�ȼ��ţ��ȴ��һ����ɫ�Ļ��棬�������д�ֻ
��һ���������ˣ���ͷɢ�����²�����ĸߴ��������ĸ�������۵�����������֫
�ǽ���εĵ��ڵ��С�����ɢ���ŵ����Ϳ��ʷ��˵��̾ߣ���ǰ�棬��һ���ߴ�
���ɵ�¯���������һ��Ĵܣ����з·�����һ�㡣������ 
LONG
	);
	set("no_clean_up", 0);
	set("no_fly",1);
	set("exits",([
		"west" : __DIR__"jq2-exit",
		
	]));
        set("objects", ([
                __DIR__"npc/jq2-guosongyang" : 1,
        ]) );
        set("item_desc", ([
		"����": "����������۵�������������������֫��ֻ���þ������������ϣ�pull����\n",
		"shackle": "����������۵�������������������֫��ֻ���þ������������ϣ�pull����\n",
		"chain": "����������۵�������������������֫��ֻ���þ������������ϣ�pull����\n",
	]) );
	setup();
	
}


void	init(){
	add_action("do_pull","pull");
}

int do_pull(string arg){
        object me,ob;
        int i;
        me=this_player();
        ob=this_object();
        
        if (me->is_busy())
        	return notify_fail("��������æ��\n");
        	
        if (!arg && arg!="����"&& arg!="shackle") {
                tell_object(me,"��������ʲô��\n");
                return 1;
        }
        if (!ob=present("guo songyang",this_object())) {
                tell_object(me,"��������ʲô��\n");
                return 1;
        }
        if (ob->query("loose")) {
                tell_object(me,"���������ϵ������Ѿ����⿪�ˡ�\n");
                return 1;
        }
        if (me->query("force_factor")>= 70) {
        	message_vision(HIC"$N˫���ս�������������Ϣ��ת���͵ش��һ������������������Ӧ�����ϣ�\n"NOR,me);
        	ob->set("loose",1);
        	ob->delete_temp("condition_type");
        	me->start_busy(4);
        	call_out("kill_him",6,me,ob);
        }
        	else {
        	message_vision(CYN"$N�������������������޶�������enforce 70��\n"NOR,me);
        }
              
        return 1;
}


int kill_him(object me, object ob){
	if (!me || !ob || environment(me)!= environment(ob) )
		return 1;
	ob->delete("NO_KILL");
	message_vision(HIR"
����������̧��ͷ����Ŀ�𽥻ָ�����ɡ�������ȴ��һ������֮����ȫ���
����Ѹ�������������·�Ҫը��һ�㡣 

������������ϵĳ��������쳤Х���ѽ��ƣ������ŭ�����ɱ��ɱ��ɱ��ɱ��ɱ�� \n\n\n"NOR,me);
	ob->kill_ob(me);
	ob->carry_object("obj/weapon/sword");
	ob->ccommand("wield sword");
	return 1;
}


string *event3_msg=	({
	
	HIW"\n��Ȼ��һ�����ݵؿ�Ц��Զ����Ѹ�ٴ�������\n"NOR,
	
	HIW"\n�����أ����أ�̤����Ь���ٴ�������ȫ���ѹ��򣬹��������������� \n"NOR,
	
	HIW"\nһֻ����������־����쵽����ǰ����û����ع��������Ѵ��������������޼�ľ��\n"NOR,

	HIW"\n������һ����ʮ��������ָ��������Ŀڣ���������δ��ϣ��ѵ�ֻ�ñ�Ŀ������\n"NOR,

    	HIW"\nʮ����ָ��Ҫ�������Ŀڵ�һɲ�ǡ�\n"NOR,
    
    	HIC"\n��һɲ�ǡ�������\n\n\n"NOR,
    	
	HIR"\n\n�ɵ��֡�\n"NOR,
	
	HIR"С��ɵ��������鷢��\n"NOR,
	
	HIR"\n    ��������\n"NOR,
	
	HIR"���ؿ�һ���ʹ����δ���徿���Ƿ�����ʲô�����ε��˹�ȥ��\n"NOR, 

});


void event3(object me, int count)
{
	object room, li;
	
	
	if ( !me || environment(me)!= this_object() ) 	return;
		
	tell_object(me,event3_msg[count]+"\n");
	if(++count==sizeof(event3_msg))
	{
		
		me->set_temp("maze/see_li",1);
		me->stop_busy();
		me->unconcious();
		room = find_object(AREA_FY"fysecret");
		if (!room) room = load_object(AREA_FY"fysecret");
		REWARD_D->riddle_set(me,"�ٴ���Ǯ",4);
		me->move(room);
		return;
	}
	else call_out("event3",1,me,count);
	return ;
}
