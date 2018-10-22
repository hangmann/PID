#ifndef PID_H
#define PID_H
#endif

template <class T1, class T2>
class PIDController
{
public:
  PIDController(double p, double i, double d, T1 (*pidSource)(T2* fContext), void (*pidOutput)(T1 output, T2* fContext));
  PIDController(double p, double i, double d, T1 (*pidSource)(T2* fContext), void (*pidOutput)(T1 output, T2* fContext), T2* context);
  void tick();
  void setTarget(T1 t);
  T1 getTarget();
  T1 getOutput();
  T1 getFeedback();
  T1 getError();
  void setEnabled(bool e);
  bool isEnabled();
  T1 getProportionalComponent();
  T1 getIntegralComponent();
  T1 getDerivativeComponent();
  void setMaxIntegralCumulation(T1 max);
  T1 getMaxIntegralCumulation();
  T1 getIntegralCumulation();

  void setInputBounded(bool bounded);
  bool isInputBounded();
  void setInputBounds(T1 lower, T1 upper);
  T1 getInputLowerBound();
  T1 getInputUpperBound();
  void setOutputBounded(bool bounded);
  bool isOutputBounded();
  void setOutputBounds(T1 lower, T1 upper);
  T1 getOutputLowerBound();
  T1 getOutputUpperBound();
  void setFeedbackWrapped(bool wrap);
  bool isFeedbackWrapped();
  void setFeedbackWrapBounds(T1 lower, T1 upper);
  T1 getFeedbackWrapLowerBound();
  T1 getFeedbackWrapUpperBound();

  void setPID(double p, double i, double d);
  void setP(double p);
  void setI(double i);
  void setD(double d);
  double getP();
  double getI();
  double getD();
  void setPIDSource(T1 (*pidSource)(T2* context));
  void setPIDOutput(void (*pidOutput)(T1 output, T2* context));
  void setPIDSource(T1 (*pidSource)());
  void setPIDOutput(void (*pidOutput)(T1 output));
  void registerTimeFunction(unsigned long (*getSystemTime)());

  void reset();
private:
  T2* context;

  double _p;
  double _i;
  double _d;
  T1 target;
  T1 output;
  bool enabled;
  T1 currentFeedback;
  T1 lastFeedback;
  T1 error;
  T1 lastError;
  long currentTime;
  long lastTime;
  T1 integralCumulation;
  T1 maxCumulation;
  T1 cycleDerivative;

  bool inputBounded;
  T1 inputLowerBound;
  T1 inputUpperBound;
  bool outputBounded;
  T1 outputLowerBound;
  T1 outputUpperBound;
  bool feedbackWrapped;
  T1 feedbackWrapLowerBound;
  T1 feedbackWrapUpperBound;

  bool timeFunctionRegistered;
  T1 (*_pidSource)();
  void (*_pidOutput)(T1 output);
  T1 (*_pidSourceContext)(T2* context);
  void (*_pidOutputContext)(T1 output, T2* context);
  unsigned long (*_getSystemTime)();
};
