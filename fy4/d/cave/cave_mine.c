/*��������������������������������  С���� 
���������������������������������� �� 
�������� �� ������ �� �������� �� ������ �� �춫���� �� ������ �� ������ 
���������������������������������� ������������������������        ���� 
�������ţ�������������       	  ���Σ���������������           ���춫�� 
���������������������� ����������������	  ������������		���� �� 
    ��		    С�ַ�	  ����				     ��	
    ��		      ��	   ��  				     ��	
������·����������  ��ʳ��       �챱���ţ��������������� 	 ���춫· 
��������������������������������   ������������������������	   ���� 
���е������е����š����е�        ��ͥ �� ���е���       ���� �� ���е��� 
���������������������� ����������  ����������������������    ��     ������ 
������·�����������ϵ���˪��    �������ţ���������  ��          ���춫·��ľ�� 
��  ������������������������������ ������������������������         �� 
��ˮ�Σ�����������������������   ������·��������������          ���춫�� 
���������������������������������� ������������������������         �� 
�����Ͻ� �� �����ϵ� �� ������ ����ʯ��· �� ������ �� �춫�ϵ� �� ���Ͻ�
			
*/

#include <ansi.h>
inherit ROOM;

int valid_leave(object obj, string dir){
		object ob, *inv;
		int i,n;	
		string block_dir, *blocker;
		string *npc = ({
			"������","�����","������","����¹",
			"��ˮ��","��ľ��","�����","��ľ�",
			"ţ����","������","Σ����","�һ���",
			"��ˮ�","��ľ��","������","ص����","���º�"
		});
		string *npc_e = ({
			"a", "b", "c", "d",
			"e", "f", "g", "h",
			"i", "j", "k", "l",
			 "m", "n", "o", "p","q"
			});
		switch (query("short")) {
				case	"������·": blocker = ({ "a", "b", "c", "d" }); 
								block_dir = "north"; 
								break;
				case	"���е���": blocker = ({ "a", "b", "c", "d" }); block_dir = "north"; break;
				case	"������·": blocker = ({ "a", "b", "c", "d" }); block_dir = "north"; break;	
				case	"��������": blocker = ({ "a", "b", "c", "d" }); block_dir = "south"; break;
				case	"������": 	blocker = ({ "e", "f", "g", "h" }); block_dir = "west"; break;
				case	"��������": blocker = ({ "e", "f", "g", "h"}); block_dir = "east"; break;
				case	"������": 	blocker = ({ "e", "f", "g", "h"}); block_dir = "east"; break;				
				case	"�춫����": blocker = ({ "e", "f", "g", "h"}); block_dir = "east"; break;
				case	"������": 	blocker = ({ "e", "f", "g", "h" }); block_dir = "west"; break;
				case	"���춫��": blocker = ({ "i", "j", "k", "l" }); block_dir = "south"; break;		
				case	"���춫·": blocker = ({ "i", "j", "k", "l" }); block_dir = "north"; break;	
				case	"���е���": blocker = ({ "i", "j", "k", "l" }); block_dir = "south"; break;	
				case	"���춫·": blocker = ({ "i", "j", "k", "l" }); block_dir = "south"; break;	
				case	"���춫·": blocker = ({}); block_dir = ""; break;		// ����	
				case	"�춫�ϵ�": blocker = ({ "m", "n", "o", "p","q" }); block_dir = "west"; break;
				case	"������": 	blocker = ({ "m", "n", "o", "p","q" }); block_dir = "west"; break;
				case	"��ʯ��·": blocker = ({ "m", "n", "o", "p","q" }); block_dir = "west"; break;
				case	"������": 	blocker = ({ "m", "n", "o", "p","q" }); block_dir = "east"; break;
				case	"�����ϵ�": blocker = ({ "m", "n", "o", "p","q" }); block_dir = "west"; break;
				}	
		
//		CHANNEL_D->do_sys_channel("sys", sprintf("location is %s, blocker is %O, time is %d\n",query("short"),blocker, time()-query("cave_mine")));
		
		if(dir == block_dir && sizeof(blocker)>0 ){
			inv = all_inventory();
			if (inv && sizeof(inv))
				for (i=0;i<sizeof(inv);i++) {
					if (inv[i]->query("cave_killer")) {
						ob = inv[i];
						break;
					}
				}
							
			if (ob)	
				return notify_fail(ob->name()+"����ס�����·��\n");
			else if (query("cave_mine")+ 20 < time() && random(10)>7) {
				seteuid(getuid());
				
				if ( (n = member_array(obj->query("quest/quest"), npc)) != -1 //	killer quest
					&& member_array(npc_e[n], blocker)!= -1)				  // And that killer is in current area list
				{
					ob = new(__DIR__"npc/killer_"+npc_e[n]);			// We generate this killer immediately	
					ob->set("combat_exp", obj->query("combat_exp"));		// Killer skill/pfm sucks.. so same exp 
					"/feature/nada"->reset_npc(ob);
					ob->full_me();
					ob->set("title",HIC"����ɱ��ͷĿ"NOR);
				} else
				{			
					ob = new(__DIR__"npc/killer_"+ blocker[random(sizeof(blocker))]);
				}
			
				ob->move(this_object());
				message_vision(HIB"·�ߺ�Ӱһ��!$N�ȵ���ʲô�˸�˽�������ᣬ��������\n"NOR, ob);	
				ob->kill_ob(obj);
				return notify_fail("");
			}
		}	
		return ::valid_leave(obj, dir);
}
