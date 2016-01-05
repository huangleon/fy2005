#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{

	object room,ob,coin;
	string rname,str;
	string *driddle = ({"������÷","����ɽׯ","�����Թ�","����Ů��",
		"�ؾ�¥","��ɽ̽��","������ɽ","ɳĮ����","����ͭ��","�´�����","̽������","��ˮ̽��","����կ����"});
	string *content = ({"��÷ɽׯ������",
						"����ɽׯ������",
						"������������",
						"����ȵ���Ҷ",
						"����������",
						"������ɽǰɽ",
						"������ɽ��ɽ",
						"����կ������",
						"�����˹�����",
						"������𵺵Ķɴ�",
						"��������ڵĴ���",
						"΢�ͷ���",
						"��Ǯ����",
					});
	int i;
	
	seteuid(getuid());	
	if (!REWARD_D->check_m_success(me,"��������"))
		return notify_fail("�㻹û�м�����������������������ĸ���\n");
	
	if (arg == "-coin") {
		if (me->query("deposit")< 100)
			return notify_fail("��û���㹻�Ĵ����ִ�д�ָ�\n");
		if (me->query("timer/keychain_coin")+ 300 > time())
			return notify_fail("������ÿ�����Ӳ���ִ��һ�Ρ�\n");
		coin = new("/obj/money/coin");
		coin->set_amount(50);
		if (!coin->move(me)){
			destruct(coin);
			return notify_fail("��Я����Ʒ���࣬�޷�ִ�д�ָ�\n");
		}
		write(WHT"���������������죬������ʮ��ͭ������\n"NOR);
		me->add("deposit",-50);
		me->set("timer/keychain_coin",time());
		return 1;
	}
	
	if (arg=="-list") {
		write(WHT"    ���Ƶ��������;������Ӧ����
=======================================\n\n"NOR);		
		for (i=0;i<sizeof(driddle);i++){
			str = (REWARD_D->check_m_success(me,driddle[i]))?
					CYN""+ driddle[i]+""NOR	: driddle[i];
			write(sprintf(YEL"  %-20s"NOR"%-20s\n",
				content[i],
				str,
				));
		}
		write(WHT"
=======================================\n"NOR);
		return 1;
	}		
		
	if (arg)	 
		return notify_fail("�������Ҫ����������������������Ļ����Զ��жϡ�\n");
		
	room = environment(me);
	rname = file_name(environment(me));
	
//	write(" it is "+ file_name(environment(me))+"\n");
	
	if (me->query("deposit")<100)
		return notify_fail("ʹ������������Ҫ������һ����ʵ������\n");
	me->add("deposit",-100);	
		
	switch (rname) {
		
		case "/d/wanmei/gate":
			if (REWARD_D->check_m_success(me,"������÷")) {
				message_vision("$N�����Ͻ��¹��٣�����һ����Ȫˮ���������ָ����к������
��ɽ��÷��ɳɳ���죬�ƺ�Ҳ��Ϊ��鳪��ׯ�ڵ�ɱ����ʱ��ɢ�ˡ�\n",me);
				me->set_temp("played_qin",1);
				return 1;
			}
			break;
		case "/d/ghost/forest9":
			if (REWARD_D->check_m_success(me,"����ɽׯ")){
				message_vision("$N������ͳ�һ������೤��ͭ�ڴ���һ����\n",me);
        		room->pipe_notify();
        		return 1;
        	}
        	break;
		case "/d/eastcoast/seaside":
		case "/d/eastcoast/seaside2":
		case "/d/changchun/island":
			if (REWARD_D->check_m_success(me,"�����Թ�")){
				message_vision("$N������ͳ�һ������೤��ͭ�ڴ���һ����\n",me);
        		room->pipe_notify();
        		return 1;
        	}
        	break;
		case "/d/eastcoast/troad3":
			if(REWARD_D->check_m_success(me,"����Ů��")){
				me->set_temp("mark/cat",1);
				message_vision("$N��Сè��գ��գ�۾���Сè���ƺ�������$N���ܹ�����$N�Ľ��ϲ��˲䣬
�����צ�������ߵ�ɽ��ָ��ָ���ܿ��ˡ�\n",me);
				return 1;
			}
			break;
		case "/d/shaolin/ye1":
		case "/d/shaolin/ye2":
			if (REWARD_D->check_m_success(me,"�ؾ�¥")){
				message_vision("$N������������Ϊ�����һ���ʧ��ľ��飬��λʦ��Ī�ǲ��ǵ���ô��\n",me);
				me->set_temp("shaolin",1);
				return 1;
			}
			break;
		case "/d/wolfmount/bigstage":
			if (REWARD_D->check_m_success(me,"��ɽ̽��")){
				if(objectp(ob=present("fighter wolf",room))) {
					message_vision("$N������$n�ļ�˵����λ�ֵܣ��ϴε�Ұζ����ɡ�
$n��Ц�����������������Ǽ��ò���Ұ���㰡��\n", me, ob);
					me->set_temp("marks/��ɽ�ο�",1);
					return 1;
				}
			}
			break;
		case "/d/wolfmount/brook":
			if (REWARD_D->check_m_success(me,"������ɽ")){
				me->set_temp("annie/wolf_conch",1);
				message_vision("$N������ͳ�һ��С���ݣ������ش��˼�����\n",me);
				return 1;
			}
			break;
		case "/d/oldpine/keep2":
			if (REWARD_D->check_m_success(me,"ɳĮ����")){
				message_vision("$N����ɤ�Ŷ���ѧ��С���˵�����ߺ���˼�����\n",me);
				room->pipe_notify();
				return 1;
			}
			break;

		case "/d/qianfo/dadian":
			if (REWARD_D->check_m_success(me,"����ͭ��")){
				message_vision("$N�������ͳ���öС�����ͭ���С�\n",me);
				me->set_temp("marks/copperman",1);
				return 1;
			}
			break;
		case "/d/eastcoast/bfd1":
			if (REWARD_D->check_m_success(me,"�´�����")) {
				tell_object(me, "���ɣ�����ͣ��һ���󴬣����ϲ��������������������˴󺣴�.......\n\n" NOR ) ;
	  			message_vision("����һ��$N�ϴ���æ����һ��������ඣ�\n", me);
	  			message_vision("�������𷫣������򶫷����С�\n\n", me);
	  			room = find_object(AREA_BAT"dahai");
	  			if (!room)	room = load_object(AREA_BAT"dahai");
	  			me->move(room);
				return 1;
			}
			break;
		case "/d/bawang/ehugang":
			if (REWARD_D->check_m_success(me,"̽������")) {
				message_vision("$N�ӵ���ץ��Щ����������Ĩ��Ĩ���ְ��·����˼������ӣ�һȳһ�յ�����������ޡ�
������������˵��Сɽ�������ϴε��ռ������Ժ���Ӽ�������ү��
С��޵�ͷ���ż��ᣬ���ͷ��������ָ��ָ��\n",me);
				me->set_temp("marks/keychain_ehg",1);
				return 1;
			}
			break;
		case "/d/laowu/baishui":
			if (REWARD_D->check_m_success(me,"��ˮ̽��")){
				ob = new(AREA_QINGPING"npc/obj/kite");
				room->kite_notify(ob,1);
				return 1;
			}
		case "/d/zangbei/wild3":
			if (ob=present("bandit",room)){
				if (me->query("deposit")>10000) {
					message_vision("$N���������ͳ�һ����Ʊ��������Ц�صݸ�$n\n",me,ob);
					me->add("deposit",-10000);
					if (me->query_temp("wild4_pass") || me->query("combat_exp")<1000000)
						ob->ccommand("say ��ô���������ͱ�·�����ˣ�");
					me->set_temp("wild4_pass", 1);
					ob->ccommand( "say ������������Т˳�ķ��ϣ��͸��������ɡ�");
					return 1;
				} else
					message_vision("$N˵����л��ӣ�ûǮ��ȥȡ��\n",ob);
				return 1;
			}
			break;
					
	}

	me->add("deposit",100);	// û�����ã���Ǯ
	
//	write ("not exec \n");
	return notify_fail("��������û��ʲô��Ӧ������ǵط����ԣ�������û�����Ӧ�����⡣\n");
}


int help(object me)
{
	write(@HELP
[0;1;37m����������������������������������������������������������������[0m
[0;1;36mָ���ʽ�� keychain [-list | -coin ][0m
[0;1;37m����������������������������������������������������������������[0m

���������Ƿ��ƣ���������������к��Ƴ�����һ��ͷ���������
��ǿ��ϷȤζ�Եı��

����������������Ҫ���պ��ܽ��룬��ÿ�ν�����Ҫ�ռ�����
��Ʒ����һЩ���ܳ������ߵ���Ҵ��������ѡ�

�������������Ͳ�����Ϊ��������ˣ�

ֻҪ������������������Ӧ�����⣬���������ͻὫ�й���Ʒ��
���ղ��������Ȳ�ռ�ط���Ҳû���������಻����Ϊ�����߶���ʧ��
�����ٴ�������Ҫ������Щ����ʱ��ֻ����ԭ�����յĳ�������
������������������ͻ�������Ӧ�ķ�Ӧ��������ʲô��
��ʹ�ã��Ϳ����Լ���ĥ�ˡ�

ʹ�ã�������������������ɲ쿴���������������
�����е�������Ʒ���Ƿ���ɿɴӲ�ͬ����ɫ������

ע�������һЩ�����Ѿ����������Գ�������⣬��û��ʹ������
�����ı�Ҫ������˵����֡�����ɽׯ�������õȵȡ�һЩ���Է�
�����׳��벻Ҫ������Ʒ�ĵ�����������Ҳ�����á�

ע����ÿ�γɹ�ʹ��������������������˻���ת�ߣ���������
���������˹������֡���ɽ����÷�Ⱥܶ�ط����ߺ�ֻ��Ҫʹ��һ
�α�ɸ������ǣ�������������Ǵ����ģ�

ע�������ʹ�� -coin ��������ɴ�������õ���ʮ��ͭ�壬��Ҳ
���õ�������ĳ���Թ����ˡ�

[0;1;37m����������������������������������������������������������������[0m
HELP
	);
	return 1;
}
