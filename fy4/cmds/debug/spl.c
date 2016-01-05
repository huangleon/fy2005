 // learn.c
/*      -- Modified by Silencer for FY4.1

(1)     Using Difficulty instead of learn_bonus to describe skill learning.
(2)     Removed Randomness in learning .

*/

#include <skill.h>

inherit F_CLEAN_UP;

string *reject_msg = ({
        "˵������̫�����ˣ�������ҵ���\n",
        "�����ܳ�����һ����˵������̣�������ҵ���\n",
        "Ц��˵��������Ц�ˣ��������С�������ʸ�ָ�㡹��ʲ�᣿\n",
});

int couple_learn(object me, object couple, string skill);
void create() { seteuid(getuid()); }

int main(object me, string arg)
{
        string skill, teacher, master;
        string target, cardname;
        object ob, *list, marry_card;
        int master_skill, my_skill, gin_cost;
        int i,marry_flag, level;
        int amount=0, pot;
                int maypr;
                int flag,pot2,amountc,potleft;
                mapping skl, lrn, map;
                int skill_basic,skill_a,skill_prac_limit,capped;
                string ric;    
                string *att_skill = ({ "literate", "unarmed", "force", "foreknowledge", "chanting", "move" });

        set_eval_limit(1); 
        seteuid(getuid());

        if(!arg || sscanf(arg, "%s from %s with %s cap %d", skill, teacher,ric,capped )!=4 )
                return notify_fail("ָ���ʽ��spl <����> from <ĳ��> with <��������(д1��û��)> cap <�ȼ�>\n");

        if( !(ob = present(teacher, environment(me))) || !ob->is_character())
                return notify_fail("��Ҫ��˭��̣�\n");
    
        target = (string)me->query("marry");
    
        if( !master_skill = ob->query_skill(skill,1) )
                return notify_fail("���������±����ұ���ѧ�ˡ�\n");
    
        if(!me->is_couple_of(ob)){ 
                if(ob->prevent_learn(me, skill)) 
                return notify_fail(ob->name() + "��Ը���������ܡ�\n");
        }
        
        my_skill = me->query_skill(skill, 1);
        if( my_skill >= master_skill )
                return notify_fail("�������ĳ̶��Ѿ���������ʦ���ˡ�\n");

                flag = 0;
                
                if (capped <= my_skill)
                        flag=3;

                if (my_skill >= ob->query_skill(skill,1))
                        flag=5;


        // ���������������Ӧ�Ļ���������ѧϰʱϵ����1.5���㡣
        if ( member_array(skill, att_skill) == -1)
                my_skill = my_skill * SKILL_D(skill)->effective_level(me)/100;
        else
                my_skill = my_skill * 150 /100;
    
        notify_fail("����Ŀǰ��������û�а취ѧϰ���ּ��ܡ�\n");
        if( !SKILL_D(skill)->valid_learn(me) )  return 0;

        tell_object(me,"����"+ob->name()+"����йء�"+ SKILL_D(skill)->name() +"�������ʡ�\n");
    
/*

check if i can practice this?

*/
        if (ric != "1")
                maypr=1;
/*
check if i can practice this?
*/
        
                if((my_skill * my_skill * my_skill)/10  > (int)me->query("combat_exp") )
                        flag=1;

                pot = 0;

                for (int g=0; g<400; g++)
                {
                reset_eval_cost();

                        potleft=me->query("potential") - me->query("learned_points");
                        if (potleft == 0)
                                flag = 2;
                
                        if (flag != 0)
                        {
                                tell_object(me,"return : "+flag+"\n");
                                return 1;
                        }

                        if (maypr)
                        {
                                skill_prac_limit = SKILL_D(skill)->practice_limit() > 100 ? 100 : SKILL_D(skill)->practice_limit();
                                if( me->query_skill(skill,1) < skill_prac_limit)
                                        me->improve_skill(skill, 99999, 1);
                        }

                        skl = me->query_skills();
                        lrn = me->query_learned();

                        // trying to learn from master.

                        amountc = (skl[skill]+1)*(skl[skill]+1)+1-lrn[skill];
                        // amount we need to learn, to calc pots cost.

						amount = 400 + 30 * me->query_int();
                                
                        if (me->query("national")=="����")      
                                amount = amount * 110/100;      // ��������
                        
                        amount = amount * 2 / SKILL_D(skill)->skill_difficulty();
                                                                                                                        
                        if( amount < 1) amount = 1;             // ����1��1             

                        pot2 = amountc / amount;

                        if (pot2 <= 0)
                                pot2 = 1;
                        
                        if (pot2 > potleft)
                        {
                                pot2=potleft;
                                amountc=amount*pot2;
                                flag=1;
                        }

                        me->add("learned_points",pot2);
                        me->add("annie/skill_cost/"+skill,pot2);
                        me->improve_skill(skill, amountc, 0);

//                      pot = pot+pot2;
                my_skill = me->query_skill(skill, 1);

                        if (capped <= my_skill)
                                flag=3;

                        if (my_skill >= ob->query_skill(skill,1))
                                flag=5;

                        if ( member_array(skill, att_skill) == -1)
                                my_skill = my_skill * SKILL_D(skill)->effective_level(me)/100;
                        else
                                my_skill = my_skill * 150 /100;

                        if((my_skill * my_skill * my_skill)/10  > me->query("combat_exp") )
                                flag=4;


                }

        return 1;
}
