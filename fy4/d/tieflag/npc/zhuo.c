// zhuo.c
#include <ansi.h>
inherit NPC;


void create()
{
        set_name("׿����", ({"zhuo"}) );
        set("gender", "Ů��" );
        set("nickname", "����");
        set("age", 36);
        set("agi",30);
        set("no_arrest",1);
        set("per", 30);
        set("long","����׿�����Ṧ������˫���ڱ��丳������������\n"	);
        
        set("combat_exp", 1100000);
        set("score", 10000);
    
        set_skill("move", 150);
        set_skill("force", 100);
        set_skill("parry", 150);
        set_skill("dodge", 150);
        
    	set_skill("meihua-shou", 150);
    	set_skill("qidaoforce", 150);
    	set_skill("feixian-steps", 120);

     	map_skill("unarmed", "meihua-shou");
        map_skill("force", "qidaoforce");
        map_skill("dodge", "feixian-steps");
        map_skill("move", "feixian-steps");
        
        set("chat_chance",1);
        set("chat_msg",({
        	"׿����˵������������Ҫ���������߻�������ô�����Ǵ�����֮�ˣ���\n",
        	"׿����˵������������ܰ������ǣ����ǾͿ��Եõ�ҹ�۵ı��أ����񹦱��䣡��\n",
        	}) );
		setup();
        carry_object("/obj/armor/cloth")->wear();  
}

void init()
{
    	object me;
    	::init();
    	if( interactive(me = this_player()) && !is_fighting() ) {
	        remove_call_out("greeting");
	        remove_call_out("feng_revive");
	        if (REWARD_D->riddle_check(me, "��������")== 1
	        	|| me->query_temp("marks/����"))	    
	        {
	        	command("say ��֪����Ķ�������"+RANK_D->query_self_rude(this_object())+"��ѵ��ѵ�㣡");
	        	this_object()->kill_ob(me);   
	            return;
	        }
		    call_out("greeting", 1, me);
	        add_action("do_accept","accept");
	        return;
        }
}

void greeting(object me)
{
		object feng;
    	if (feng=(present("feng jiuyou",environment()) )  )
    	if (base_name(feng)==__DIR__"feng" )
       		command("say �����������ﱾ��ȡ��ҹ�۵ı��أ�û�뵽�����ĺ�Ȼ�߻���ħ��
�����Ը��������ǣ�ҹ�۵ı��ؾ�������ˡ�(accept yes/accept no)\n");
          	
}

int do_accept(string arg)
{
	object feng;
    object me;
	if (!arg || (arg!= "yes" && arg !="no")) return 0;
    me=this_player();
    if (me->is_fighting()) return 0;
    if (arg=="yes")
    {
    	if (!feng=(present("feng jiuyou",environment()) )  ) 
    	{
    		command("sigh");
			command("say û�з����ģ����������Ҳ�ǰ״");
	    	return 1;
		}
		if (base_name(feng)!=__DIR__"feng" )
		{
			command("grin");
			command("say �������Ѿ����ˣ����ǻ�Ҫ�����\n");
			return 1;
		}	
    	message_vision( YEL "$N��������$n�ĺ��ģ�������������\n"NOR,me,feng);
    	me->start_busy(4);
		if (me->query("force")<200)
		{
			tell_object(me,"���������������Ү��\n");
			return 1;			
		}
		message_vision(CYN"$NЦ��������˺��ģ��Ҿ͸���������ܰɡ�\n"NOR, me);
        tell_object(me,CYN"׿�������ĵض���˵�����ߵĶ��˹������и��󱦲ء���\n"NOR);
        message_vision(CYN"׿���Ｗ�˼��۾��������������Ĳ�һ��Ը�������Ŷ��\n"NOR, me);
        me->set("force",0);
        REWARD_D->riddle_set( me,"��������", 2);
        call_out("feng_revive",5,me,feng);
    }
    else
    {
      	command("say ��֪����Ķ������������ѵ��ѵ�㣡");
      	this_object()->kill_ob(me);
      	me->kill_ob(this_object());
      	if (!feng=(present("feng jiuyou",environment()) )  ) 
    		 	return 1;
	  	if (base_name(feng)!=__DIR__"feng" )
		{
			feng->kill_ob(me);
			me->kill_ob(feng);
			return 1;
		}
		me->set_temp("marks/����",1);	
	    call_out("feng_revive",20,me,feng);
    } 
    return 1;                                          
}


void feng_revive(object me,object feng)
{
	object lishi;
	object ark;
	object woman;
	int damage;    
    string myfile;
    myfile=base_name(this_object());
    //I do not want to specify an abs name of a room
    myfile=replace_string(myfile,"npc/zhuo","ark");
	if (environment(me)!=environment(this_object())) return;
	if (!feng)	return;
	if (!living(feng)) return;
	destruct(feng);
	feng=new(__DIR__"feng2");
	feng->move(environment());
	message_vision(YEL"\n\n$N������һ������վ��������\n"NOR,feng);
	message_vision(YEL"$N�ȵ���������ʿ���ڣ���\n\n"NOR,feng);
	lishi=new(__DIR__"lishi");
	lishi->move(environment()); 
	message_vision(WHT"\nһ����ͭɫ�Ĵ󺺳�����$N����ǰ��\n\n",feng);
	if (!objectp(ark=find_object(myfile)))
    	ark=load_object(myfile);
	if (!me->query_temp("marks/����"))
	{
    	message_vision(YEL"$n˵��������ʿ������һ��֮���ɣ�\n"NOR,me,feng);
    	message_vision(YEL"$n���һ����һ��ץס$N�����죬��$N���۶�ȥ��\n\n"NOR,me,lishi);
    	me->move(ark);
    }
    else
    {
    	message_vision(YEL"$N���һ�������ҹ��ۼҵ����£������ò��ͷ��ˣ���\n"NOR,feng);	
    	feng->kill_ob(me);
    	lishi->kill_ob(me);
    	message_vision( HIR "\n����ʿ��Ȼ����һȭ������$N�������ϡ�\n"NOR,me);
    	damage=500+random(750);
        me->receive_damage("kee",damage,lishi);
        COMBAT_D->report_status(me);
        message_vision( HIR "$N�����ӱ��������ߵķ���һ�������ɫ�Ĵ������þò��������֮����\n\n"NOR,me);
        me->move(ark);
        if((woman=present("old woman",ark)) && me->query("kee")>0 )
        {
        	me->unconcious();
        	call_out("me_revive",9,me,woman);
        }
    }
    return;
}       

 
void me_revive(object me,object woman)
{                                                                      
		me->delete_temp("marks/����");
		if (REWARD_D->riddle_check(me,"��������"))	return;
		
		me->revive();
		if (environment(me)!=environment(woman)) return;
	
		message_vision(CYN"\n$N̾�����������ĺ��ӣ����������Ϊ�Ҷ�֪���ˡ���\n"NOR,woman);
		message_vision(CYN"$N˵��������һ��ά�����ң��ұ��ð���㣬�������ڡ���
�Ҿ͸�����һ�����ܰɡ�
�������������湦�������񹦺����񹦣�����Ե�߲��ܵ�֮��
���ӣ������Ϊ֮������һ��������������Ļ�Ե�ġ�\n\n"NOR, woman);
		REWARD_D->riddle_set(me,"��������", 1);
		
		return;
}
