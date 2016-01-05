inherit NPC;
void create()
{
    	set_name("С��ȸ", ({ "skylark" }) );
        set("race", "����");
        set("age", 2);
        set("gender", "����");
        set("long", "��ë����ýྻ���룬ߴߴ�����ܿɰ���С��ȸ��ץס��catch�����ɡ����� \n");
	set("combat_exp", 10000);
        set("attitude","peaceful");
        
        set_temp("apply/dodge", 100);
	set("chat_chance", 1);
        set("chat_msg", ({
        	"С��ȸߴߴ��������Ľ��ţ� \n",
        	"С��ȸ����������ë�� \n"
        }) );
        setup();
}

void init()
{	
        add_action("do_catch", "catch");
}

int do_catch(string arg)
{
	object *inv;
	object me;
	object bird;
	object birdcase;
	int i;
	me = this_player();
	bird = this_object();
	inv = all_inventory(me);
	
	if( !arg || arg != "skylark" )
                return notify_fail("��Ҫץʲô��\n");
	
	if( random(40) > me->query("kar") )
	{
		message_vision("$N����������������ۣ�һ������ʧ����Ӱ���ۡ�\n" , bird);
		destruct(bird);
	}
	else
	{
		for(i=0; i<sizeof(inv); i++)
        	if(inv[i]->query("contains"))
        	{
			birdcase = inv[i];
		}
        }
       
        if ( birdcase && random(3) )
        {
        	birdcase->set("contains",0);
        	birdcase->set("skylark",1);
        	message_vision("$Nһ��ץס$n��Ȼ��С������ذ�$n���������\n" , me,bird);
        	birdcase->set("long", "һ�����µ�С�������ʷ��Σ�һ�������ϳ���š�\n�����ֻ���õ�С��ȸ��\n");
        	destruct(bird);
        	me->start_busy(3);
        }
        else
        {
        	message_vision("$N�����$nץ�Σ�û���ϵ�һ�����ģ�$n����һ�´�$N���з����ˣ�\n" , me,bird);
        	destruct(bird);
 	}
	return 1;
}