// wizlist.c
// still@xhc
// 2000/9/9


#include <login.h>
#include <ansi.h>
inherit F_CLEAN_UP;

#define RENWU "/adm/etc/renwu"

mapping wizlevel=([
  	"(immortal)"    :   "��"HBMAG"Immortal"NOR+"����"NOR,
  	"(wizard)"       :   "��"HBCYN"wizard"NOR+"����"NOR,
  	"(arch)"       :   "��"HBGRN"arch"NOR+"����"NOR,
  	"(admin)"       :   "��"HBWHT"admin"NOR+"����"NOR,
]);


int main(object me, string arg)
{
    	string *list,wiz,quest,msg;
    	int i,j;
    	mapping quests=([ ]);
    	object ob;
    	int flag,count;

    	if (file_size(RENWU))
		foreach (string str in explode(read_file(RENWU),"\n")){
		if( str[0]=='#' || sscanf(str, "%s %s", wiz, quest)!=2 ) continue;
		quests+=([ wiz : quest ]);
    	}
    	write("��"HIR + MUD_NAME + NOR"��" + "Ŀǰ�Ŀ������Ա�У�\n");
    
	write(HIY"\n"NOR"����������������������������������������������������"HIY""NOR);
    	list = SECURITY_D->query_wizlist();
    	count=0;
    	for (i=8;i > 0;i--){
		flag=1;
		msg="";
		j=0;
		foreach (wiz in list){
		    if (wiz_level(wiz)==i){
			j++;
			if (flag){
			    msg+= "\n" + wizlevel[wizhood(wiz)]+"\n";
			    flag=0;
			}
			if (objectp(ob=find_player(wiz)) && me->visible(ob) )
			    msg+=(j%3?"":"\n")+"\t("+HIG+wiz+NOR") ";
			else
			    msg+=(j%3?"":"\n")+"\t("+wiz+") ";
			if (undefinedp(quests[wiz]))
			    msg+="(��������)";
			else
			    msg+=quests[wiz];
			count++;
		    }
		}
		write(msg);
    	}
    
	write(HIY"\n"NOR"����������������������������������������������������"HIY"\n"NOR);
    	write("�Ϲ���: "HIR+chinese_number(count)+NOR" λ��");
    	write("����"HIG"����ɫ"NOR"�ı�ʾ���߹�����Ա��\n");
    	return 1;
}

int help(object me)
{
    write(@HELP
ָ���ʽ : wizlist

��; : �г�Ŀǰ���е���ʦ������
HELP
    );
    return 1;
}



