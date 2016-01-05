
#include <login.h>
#include <ansi.h>

inherit NPC;
object player;
// Whether playing with a player
int in_game, pturn, waited;
#define NP 6
#define MAXN 15
int* p=({0,0,0,0,0,0});

string pile="�������������������";
string cnum="�٢ڢۢܢݢޢߢ���";

void show(object who);
void ctake();

int CheckWin(object who)
{
    int i, j, k;
    object ob;
    
    j = player->query_temp("marks/win_pianzi");
    k = player->query_temp("marks/lose_pianzi");
    for(i=0;i<NP;i++)
        if(p[i]!=0) return 0;
    
    message_vision(HIR"$NӮ�ˡ�\n"NOR,who);
    if(who==this_object()) {
//      player->set_temp("marks/lose_pianzi", k + 1);
        command("say ��������������ղ���ʵ��һ���Ӯ�ˡ�");
//              if (player->query_temp("marks/lose_pianzi") >= 3) {
//                      player->delete_temp("marks/lose_pianzi");
//                      remove_call_out("purple_sword");
//                      call_out("purple_sword", 2);
//              }
        player->delete_temp("marks/win_pianzi");
    } else {
        ob=new("/obj/money/gold");
        ob->set_amount(2);
        ob->move(this_object());
//        player->delete_temp("marks/lose_pianzi");
        player->set_temp("marks/win_pianzi", j + 1);
        command("say ����������������Ķ����𶧡�");
        command("give gold to "+player->query("id"));
        if (player->query_temp("marks/win_pianzi") == 2) {
//              remove_call_out("purple_sword");
                call_out("purple_sword", 1);
        }       
    }
    in_game=0;
    return 1;
} 

void take(object who, int which, int howmany)
{
    p[which]-=howmany;
    message_vision("$N�ӵ�"+chinese_number(which+1)+
                   "����������"+chinese_number(howmany)+"��Сʯ�ӡ�\n",who);
    show(0);
    CheckWin(who);
}


void show(object who)
{
    int i;
    for(i=0;i<NP;i++)
        if(p[i]!=0)
            if(who==0)
                message_vision(CYN+cnum[i*2..i*2+1]+NOR"��"GRN+
                               pile[0..p[i]*2-1]+NOR"\n",
                               this_object());
            else tell_object(who,CYN+cnum[i*2..i*2+1]+NOR"��"GRN+
                               pile[0..p[i]*2-1]+NOR"\n");
}

int do_show()
{
    if(in_game==1 && player==this_player())
    {
        show(this_player());
        return 1;
    }
    return 0;
}

int do_take(string arg)
{
    int i,h;
    if(in_game==1 && player==this_player())
    {
        if(!arg || sscanf(arg,"%d %d",i,h)!=2)
            return notify_fail("ָ���ʽ��take <�ڼ���> <�ü���>\n");
        
        if(i>NP || i<=0) return notify_fail("��ֻ��ѡ���һ����"+
                                            chinese_number(NP)+"�ѡ�\n");
        if(h>p[i-1]) return notify_fail("��"+chinese_number(i)+
                                                "����û��ô��ʯ�ӡ�\n");
        if(h<=0) return notify_fail("��ֻ����һ�����ϵ�ʯ�ӡ�\n");
        if(pturn!=1)
            return notify_fail("��û�ֵ����ء�\n");
        
        take(this_player(), i-1, h);
        remove_call_out("hurry");
        remove_call_out("ctake");
        if(in_game)
        {
            pturn=0;
            call_out("ctake",1);
        }
        return 1;
    }
    return 0;
}
    
int do_resign()
{
        int k;
        
        k = player->query_temp("marks/lose_pianzi");
    if(in_game==1 && player==this_player())
    {
        message_vision("$N�����ˡ�\n",player);
        command("say ��ô�����ˣ��㻹��ϣ��Ӯ�ģ�����");
//              player->set_temp("marks/lose_pianzi", k + 1);
                player->delete_temp("marks/win_pianzi");
//        if (player->query_temp("marks/lose_pianzi") >= 3) {
//              player->delete_temp("marks/lose_pianzi");
//         remove_call_out("purple_sword");
//              call_out("purple_sword", 2);
//        }
        in_game=0;
        return 1;
    }
    return 0;
} 

void ctake()
{
    int sum, i, j;
    int best=100, besti=-1;
    object ob;
    
    j = player->query_temp("marks/win_pianzi");
    for(i=0,sum=0;i<NP;i++)
        sum^=p[i];
    if(sum==0)
    {
        for(i=0;i<NP;i++)
            sum|=p[i];
        if(sum & 8) sum=15;
        else if(sum & 4) sum=7;
        else if(sum & 2) sum=3;
        else
        {
            command("say �������ˡ�\n");
            ob=new("/obj/money/silver");
            ob->set_amount(2);
            ob->move(this_object());
            player->delete_temp("marks/lose_pianzi");
            player->set_temp("marks/win_pianzi", j + 1);
            command("say ����������������Ķ������ӡ�");
            command("give silver to "+player->get_id());
            in_game=0;
            return;
        }
    }
    for(i=0;i<NP;i++)
        if(p[i] > (p[i]^sum) && (best > p[i]-(p[i]^sum)))
        {
            best=p[i]-(p[i]^sum);
            besti=i;
        }
    if(besti!=-1)
    {
        take(this_object(),besti, best);
        if(in_game)
        {
            message_vision(RED"��$N�ˡ�\n"NOR, player);
            pturn=1;waited=0;
            call_out("hurry",10);
        }
        return;
    }
    command("say shit!������\n");
    message_vision("$N��ʯ������������\n"NOR, this_object());
    in_game=0;
}

int do_start()
{
    int i,sum=0;
    object silver;
    int *mp;
    
    if(in_game==1) 
        return notify_fail(HIC"����ƭ��"NOR"�ں�"+player->name()+"�����ء�\n");
    //Check for money...
    player=this_player();
    silver=present("silver_money", player);
    if(!silver) return notify_fail("������û������ѽ��\n");
    silver->add_amount(-1);
                   
    in_game=1;

    mp=allocate(MAXN*4);
    for(i=0;i<MAXN;i++)
        mp[i]=0;
    for(i=0;i<NP-1;i++)
    {
        p[i]=random(MAXN)+1;
        if(mp[p[i]]==0)
        {
            mp[p[i]]++;
            sum^=p[i];
        }
        else i--;
    }
    if(random(3))  p[NP-1]=sum;
    else p[NP-1]=random(MAXN)+1;
    
    command("say ����ܼ򵥣����������ʯ�ӣ�˭���õ����һ��˭��Ӯ�ˡ�");
    command("say ��������䣨resign������鿴״̬��show����");

    show(0);
    message_vision(RED"$N���ã�take���ɡ�\n"NOR, player);
    pturn=1; waited=0;
    call_out("hurry",10);
    return 1;
}

void hurry()
{
    remove_call_out("hurry");
    if(in_game==0) return;

    if(random(10)==0 && present("old beggar",environment()))
    {
        command("say ��Ⱥ��ؤ�����ᣡ");
        call_out("hurry",10);
        return;
    }    

    if( !player || environment(player) != environment() )
    {
        command("say �ף�����ô���ˣ�");
        message_vision("$N��ʯ������������\n"NOR, this_object());
        in_game=0;
    }
    else
    {
        waited+=1;
        if(waited > 5)
        {
            command("say ��Ӧ̫�������������ˡ�");
            message_vision("$N��ʯ������������\n"NOR, this_object());
            in_game=0;
        }
        else
        {
            command("say �������ɣ�����ԥ�ˡ�");
            call_out("hurry",10);
        }
    }
    return;
}

void create()
{
    set_name(HIC"����ƭ��"NOR, ({ "jianghu pianzi","pianzi" }) );
    set("title",HIY "ͯ������"NOR);
        set("long", "һ����ˣС��Ϸƭ��Ϊ���Ľ���ƭ�ӡ�\n");
    set("gender", "����");
    set("age", 70);
    set("no_fight",1);
    set("NO_KILL",1);
    set("inquiry",([
        "��ڤ�Ͼ�" :"û��˵����\n",
        "�ķ��ڷ�" :"��ţƤ˭���ᣬ���õ��湦������ɡ�\n",
        "�ϻ۾���":	"action����ƭ���Ժ���ָ��ָ�Լ���\n",
      ]) );
              
    set("combat_exp", 9000);
    setup();
    carry_object("/obj/armor/cloth")->wear();
    in_game = 0;
}

void init()
{
    object ob;
    ::init();
    //if( !query_heart_beat(this_object()) ) set_heart_beat(1);
    add_action("do_take", "take");
    add_action("do_show","show");
    add_action("do_resign","resign");
    add_action("do_start","play");
	add_action("do_answer", "answer");
    if( interactive(ob = this_player()) && !is_fighting() )
    {
        remove_call_out("greeting");
        call_out("greeting", 1, ob);
    }
}

void greeting(object ob)
{
    if( !ob || environment(ob) != environment() ) return;

    message_vision( "$NЦ�����˵������λ" + RANK_D->query_respect(ob)
                    +"�����������С��Ϸ�ɣ�play������һ�����ӣ���ô����\n",
                    this_object());

}

int purple_sword() {
	message_vision("$N����$n������ע�������á�\n", this_object(), player); 
	message_vision("$N����$n˵�����Ҵ���������������û�м���" + RANK_D->query_respect(player) + "�������Ǵ�۵����\n", 
			this_object(), player);
	message_vision("����Ӧ������������һ����ڤ���齣�����Ը�����£��� ���������򡡣���󣯣�\n", this_object());
	player->set_temp("pianzi_yes_no", 1);
	return 1;
}

int do_answer(string arg){
	object player, sword;
	
	player = this_player();
	if (player->query_temp("pianzi_yes_no")) {
		if (arg == "yes") {
			player->set("marks/����ڤ���齣", 1); 
			message_vision("$N˵������λ" + RANK_D->query_respect(player) + "��Ȼ�м��أ�����һ�������Ӿ����ˡ�\n", 
					this_object(), player);
			player->delete_temp("pianzi_yes_no");
			return 1;
		} else if (arg == "no") {
			message_vision("$N̾�˿���˵��������ϧ����ϧ��˵ظ��������Ȼ������ʶ����\n", this_object());
			player->delete_temp("pianzi_yes_no");
			return 1;
		} else {
			tell_object(player,"answer yes/no");
			return 1;
		}
	} 
	return 0;
}


// You got the sword if you solve it and give out 100g
// But you might not be able to continue to the next step, 
// So, i will let you pawn it and let you keep a mark.
int accept_object(object who, object ob) {
	object player, sword;
	
	player = this_player();
	if (!player->query("marks/����ڤ���齣")) {
		return 0;
	}
	if (ob->query("money_id") != "gold") {
		return 0;
	}
	if (ob->query("money_id") == "gold" ) {
		if (ob->query_amount() < 100) {
			message_vision("$N�������˵�������������齣��ֵ�����Ǯ����\n", this_object());
		} else {
			sword = new(__DIR__"obj/purple_sword");
			if (sword) {
				message_vision("$NС�ĵشӻ���ȡ��һ�ѱ�������$n�ֹ����������Ī�������齣���� \n", 
					this_object(), player); 
//				sword->set("sword_owner", player->name());	//No point, as long as you have the mark you're good				
				if (sword->move(player)) {
					player->delete("marks/����ڤ���齣");
					REWARD_D->riddle_set(player,"��ڤ�Ͼ�",1);
				} else { 
					destruct(sword);
					ccommand("say OOPS������Ķ���̫���ˣ�");
				}
			}
			return 1;
		}
	}		
}
