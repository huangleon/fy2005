#include <ansi.h>
inherit SMART_NPC;
int do_running();

void create()
{
    	set_name("��С��",({"ma xiaobei","xiaobei"}));
	set("long","
С����С�������е�һ˫�ĸα�������������Ҫʲô����ȫ�������Ӧ��
���������£�����Ҳû���𱸹�����һ�䡣ֻҪһ���������ͻ������ǵ�
��ȥ�档\n");
   	
     	set("gender","����");
     	set("group","ma");
     	
    	set("age",10); 	 	
    	    	
    	
    	set("combat_exp",50000);  
    	set("attitude", "friendly");
    	
    	set("inquiry", ([
 		"*":	"���¶�ȥ���Ұ�����ɡ�\n",
   		]));

        set("arrive_msg","�����ıĵ����˹���");
    	set("chat_chance",20);
    	set("chat_msg",({
				(: do_running :),
    	}) );    	    	
    	
		
		setup();
    	carry_object("/obj/armor/cloth")->wear();
 
}

int do_running(){
	
	object room1,room2,env;
	
	if (query_busy())	return 1;
		
	env = environment();
	if (env->query("ma_room1")){
		set("leave_msg","�����ıĵش����ݱ�������");
		ccommand("go north");
		return 1;
	}
	
	set("leave_msg","�����ıĵ��ִ����ݳ������");
	ccommand("go south");
	return 1;
		
}
