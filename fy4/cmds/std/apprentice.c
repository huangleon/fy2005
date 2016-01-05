// apprentice.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
    	object ob, old_app;
    	mapping family, skills;
    	int i, score_cost;
    	string *skname;

    	if( !arg ) return notify_fail("ָ���ʽ��apprentice [cancel]|<����>\n");

    	if( arg=="cancel" ) {
        	old_app = me->query_temp("pending/apprentice");
        	if( !objectp(old_app) )
            	return notify_fail("�����ڲ�û�а��κ���Ϊʦ����˼��\n");
        	write("��ı����ⲻ���" + old_app->name() + "Ϊʦ�ˡ�\n");
        	tell_object(old_app, me->name() + "�ı����ⲻ�����Ϊʦ�ˡ�\n");
        	me->delete_temp("pending/apprentice");
        	return 1;
    	}

    	if( !(ob = present(arg, environment(me)))
        	|| !ob->is_character() )
        	return notify_fail("�����˭Ϊʦ��\n");

    	if( mapp(me->query("family")))
        if(me->query("family/privs")==1)
            	return notify_fail("��������һ��֮���������ٰݱ���Ϊʦ�ˡ�\n");
        else if(me->query("family/privs")==-1)
            	return notify_fail("����һ��֮���������ٰݱ���Ϊʦ�ˡ�\n");
    
    	if(!ob->visible(me))
    		return notify_fail("�Է��������㣬��ô��ʦ����\n");
    		
    	if( !living(ob) )
        	return notify_fail("������Ȱ�" + ob->name() + "Ū�ѡ�\n");

    	if( ob==me ) return notify_fail("���Լ�Ϊʦ��������....����û���á�\n");

    	if( me->is_apprentice_of(ob) ) {
        	message_vision("$N������������$n��ͷ�밲���е�����ʦ������\n", me, ob);
        	ob->re_rank(me);
        	return 1;
    	}

    	if( !mapp( ob->query("family") ) )
        	return notify_fail(ob->name() + "������ͽ�����޷�����Ϊʦ��\n");
    
    	if( userp(ob) && (int) ob->query("family/privs") != -1 )
        	return notify_fail("���������˲�����ͽ��\n");
        	
    	if((string)me->query("family/family_name") ==(string)ob->query("family/family_name"))
        if((int)me->query("family/generation") <= (int)ob->query("family/generation"))
            	return notify_fail(ob->name()+"�ı��ֲ�������ߣ�\n");
    
    	score_cost = ob->query("score_cost") ? ob->query("score_cost") : 1000;
    	if (!me->query("family")
    		|| me->query("family/family_name") == ob->query("family/family_name")) 
    		score_cost = 0;
    	
    	if (me->query("score")< score_cost) {
    		message_vision("$N˵���������̫��Ҳ�������Ϊͽ��������Ҫ"+score_cost+"���ۣ�\n",ob);
    		return 1;
    	}
    	
    	if (!ob->query("class"))
    		return notify_fail("��֪ͨ��ʦ�Ľ���NPC��\n");
    	
    	if (me->query("once_menpai"))
    	if (member_array(ob->query("class"), keys(me->query("once_menpai")))!=-1
    		&& me->query("family/family_name")!= ob->query("family/family_name")
    	    	) {
    		message_vision("$N˵�����Ȼ�Ѿ����������ʦ���ˣ���������ʲô��\n",ob);
    		return 1;
    	}
    	
/*    	if (me->query("family") && !me->query_temp("marks/apprentice_others")
    		&& me->query("family/family_name")!= ob->query("family/family_name")) {
    		message_vision("$N˵���������ˣ�����ʦͽ֮�壬�㻹���Ⱥ���ʦ������һ�°ɡ�\n",ob);
    		return 1;
    	}						-- So many troubles */
    	 
/*
		A ��ʦ�� B ����

		A recruit B, B apprentice, ֻҪ����ͬ�ţ�����B���ǰ��գ�B��������ʦ����B��score
		B apprentice A, A recruit, ֻҪ����ͬ�ţ�����B���ǰ��գ���������ʦ����B��score

*/ 
    	   		   	
    // If the target is willing to recruit us already, we do it.
    	if( (object)ob->query_temp("pending/recruit") == me )
    	{
        	if( mapp(me->query("family")) &&
        			(string)me->query("family/family_name") !=(string)ob->query("family/family_name") 
        			&& (string)me->query("family/title") !="��ͽ")
        	{
	            	message_vision("$N��������ʦ�ţ���Ͷ��$n���£���\n\n"
	                	"$N����������$n���������ؿ����ĸ���ͷ���е�����ʦ������\n\n",me, ob);
	            	if(me->query("score") > score_cost) 
	            		me->add("score", -score_cost);
	            	else
	            		me->set("score",0);
	            	me->add("betrayer", 1);
        	}
        	else message_vision("$N������$nΪʦ��\n\n"
                	"$N����������$n���������ؿ����ĸ���ͷ���е�����ʦ������\n\n",me, ob);

        	ob->recruit_apprentice(me);
        	ob->delete_temp("pending/recruit");
			me->delete_temp("marks/apprentice_others");
				
        	tell_object(ob, "��ϲ��������һ�����ӣ�\n");
        	family = me->query("family");
        	printf("��ϲ����Ϊ%s�ĵ�%s�����ӡ�\n", me->query("family/family_name"),
               		chinese_number( me->query("family/generation")));
			return 1;
	
    	} else {
           	
           	old_app = me->query_temp("pending/apprentice");
        	if( ob==old_app )
            	return notify_fail("�����" + ob->name() +"Ϊʦ�����ǶԷ���û�д�Ӧ��\n");
        	else if ( objectp(old_app) ) {
            	write("��ı����ⲻ���" + old_app->name() + "Ϊʦ�ˡ�\n");
            	tell_object(old_app, me->name() + "�ı����ⲻ�����Ϊʦ�ˡ�\n");
        	}
		
			message_vision("$N��Ҫ��$nΪʦ��\n", me, ob);
        	me->set_temp("pending/apprentice", ob );
        	if( userp(ob) ) {
            	tell_object(ob, YEL "�����Ը����" + me->name()+"Ϊ���ӣ��� recruit ָ�\n" NOR);
        	} else 
            	ob->attempt_apprentice(me);
	        return 1;
    	}
}


int help(object me)
{
    write(@HELP
[0;1;37m����������������������������������������������������������������[0m
[0;1;36mָ���ʽ : apprentice [cancel]|<����>[0m
[0;1;37m����������������������������������������������������������������[0m
���ָ���������ĳ��Ϊʦ������Է�Ҳ��ӦҪ����Ϊͽ�Ļ����ͻ�������
��ʦ֮�񣬷���Ҫ�ȵ��Է��� recruit ָ������Ϊ���Ӳ�����ʽ��ʦ��

��ע�����Ѿ�����ʦ�����ֱ���ʦ��Ͷ��������£�ÿ��һ�Σ�����ʦ����
����ѧ�������м��ܵȼ������20���������������ٻή��1000�㡣�����
�����۵���1000�㣬�󲿷������ǲ����������ʦ�ġ�

��Ȼ��������Ҳ��һ����ʦ�����ں����Ƿ��ѹ�ʦ��

��������ʦ��ʹ�����ָ�������ʦ���밲����Ҫ��ʦ�����������
�ĳƺš�
 
��ο����ָ�� expell��recruit
[0;1;37m����������������������������������������������������������������[0m
HELP
        );
    return 1;
}
